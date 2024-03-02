/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterHelper.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:52 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/10 13:42:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int		ScalarConverter::type = -1;
char	ScalarConverter::type_char = 'c';
int		ScalarConverter::type_int = -1;
float	ScalarConverter::type_float = 0.0f;
double	ScalarConverter::type_double = 0.0;

void ScalarConverter::convert(std::string toConvert)
{
	parseString(toConvert);
	switch(type)
	{
		case TYPE_CHAR:
			fromChar();
			break ;

		case TYPE_INT:
			fromInt();
			break ;

		case TYPE_FLOAT:
			fromFloat();
			break ;

		case TYPE_DOUBLE:
			fromDouble();
			break ;

		case TYPE_PSEUDOS:
			printPseudos();
			break ;

		default:
			throw ScalarConverter::InvalidType();
	}
	return ;
}

int countOccurrences(char ch, std::string &str) 
{
    int count = 0;
	int i = 0;
    while (str[i] != '\0')
	{
        if (str[i] == ch)
            ++count;
        i++;
    }
    return count;
}

int ScalarConverter::parseString(std::string &toConvert)
{
	if (countOccurrences('-', toConvert) > 1 || countOccurrences('+', toConvert) > 1 || \
		countOccurrences('-', toConvert) + countOccurrences('+', toConvert) > 1 || countOccurrences(' ', toConvert) > 0)
		return (-1);
	
	if (toConvert.length() == 1 && (single(toConvert) != -1))
		return (TYPE_CHAR);
	else if (pseudoLiterals(toConvert) == TYPE_PSEUDOS)
		return (TYPE_PSEUDOS);
	if (checkInt(toConvert) == TYPE_INT)
		return (TYPE_INT);
	else if (checkFloat(toConvert) == TYPE_FLOAT)
		return (TYPE_FLOAT);
	else if (checkDouble(toConvert) == TYPE_DOUBLE)
		return (TYPE_DOUBLE);
	return (0);
}
int ScalarConverter::checkInt(std::string &toConvert)
{
	if (toConvert == "-nan" || toConvert == "+nan")
		return (-1);
	char *endptr;
	double temp = strtod(toConvert.c_str(), &endptr);
	if (toConvert.find('.') != std::string::npos)
		return (-1);
	if (endptr == toConvert.c_str() || *endptr != '\0')
        return (-1);
	if (temp == HUGE_VAL || temp == -HUGE_VAL)
		return (-1);
	if (temp > INT_MAX || temp < INT_MIN)
		return (-1);
	type = TYPE_INT;
	type_int = static_cast<int>(temp);
	return (type);
}

int ScalarConverter::checkFloat(std::string &toConvert)
{
	if (isalpha(toConvert[0]))  { return (-1); }
	double temp = strtod(toConvert.c_str(), NULL);
	if ((toConvert.find('.') == std::string::npos) && (toConvert.find('f') == std::string::npos))
		return (-1);

	std::string::size_type i = 0;
	int j = 0;

	while (toConvert[i] != '\0')
	{
		if (toConvert[i] == 'f')
			j++;
		i++;
	}
	if (j > 1 || toConvert[i - 1] != 'f')
		return (-1);
	if (abs(temp) > FLT_MAX)
		return (-1);
	type = TYPE_FLOAT;
	type_float = static_cast<float>(temp);
	return (type);
}

int ScalarConverter::checkDouble(std::string &toConvert)
{
    size_t dotIdx = toConvert.find('.');
	
	if (toConvert.find('f') != std::string::npos)
		return (1);
	if (dotIdx == std::string::npos)
		return (-1);
	
	char *endptr;

    double nbr = std::strtod(toConvert.c_str(), &endptr);

    if (endptr == toConvert.c_str() || *endptr != '\0') { return (-1); }
		
	type = TYPE_DOUBLE;
	type_double = static_cast<double>(nbr);
	return (type);
}

int ScalarConverter::single(std::string &toConvert)
{
	if (isdigit(*toConvert.c_str()))
	{
		type = TYPE_INT;
		type_int = atoi(toConvert.c_str());
		return (TYPE_INT);
	}
	else if (isprint(*toConvert.c_str()))
	{
		type = TYPE_CHAR;
		type_char = toConvert[0];
		return (TYPE_CHAR);
	}
	return (-1);
}

int ScalarConverter::pseudoLiterals(std::string &toConvert)
{
	std::string	pseudoFloat[3] = {"-inff", "+inff", "nanf"};
	std::string	pseudoDouble[3] = {"-inf", "+inf", "nan"};
	int i;

	for (i = 0; i < 3; i++)	
	{
		if (toConvert.compare(pseudoFloat[i]) == 0)
			break ;
		if (toConvert.compare(pseudoDouble[i]) == 0)
			break ;
	}
	if (i < 3)
	{
		type_float = strtof(pseudoFloat[i].c_str(), NULL);
		type_double = strtod(pseudoDouble[i].c_str(), NULL);
		type = TYPE_PSEUDOS;
		return (TYPE_PSEUDOS);
	}
	return (0);
}
