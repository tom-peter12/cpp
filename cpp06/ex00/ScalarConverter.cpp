/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:18 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/10 13:54:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void ScalarConverter::fromChar()
{
	type_int =  static_cast<int>(type_char);
	type_float =  static_cast<float>(type_char);
	type_double =  static_cast<double>(type_char);

	std::cout << "Char: \t'" << type_char << "'" << std::endl;
	std::cout << "Int: \t" << type_int << std::endl;
	std::cout << "Float: \t" << std::fixed << std::setprecision(1) << type_float << "f" << std::endl;
	std::cout << "Double: " << type_double << std::endl;

	return ;
}

void ScalarConverter::fromInt()
{
	if (type_int <= 126 && type_int >= 32)
	{
		type_char =  static_cast<char>(type_int);
		std::cout << "Char: \t'" << type_char << "'" << std::endl;
	}
	else if ((type_int >= 0 && type_int <= 31) || type_int == 127)
		std::cout << "Char: \tNon displayable" << std::endl;
	else
		std::cout << "Char: \timpossible" << std::endl;

	type_float =  static_cast<float>(type_int);
	type_double =  static_cast<double>(type_int);

	std::cout << "Int: \t" << type_int << std::endl;
	std::cout << "Float: \t" << std::fixed << std::setprecision(1) << type_float << "f" << std::endl;
	std::cout << "Double: " << type_double << std::endl;

	return ;
}

void ScalarConverter::fromFloat()
{
	if (type_float <= 126 && type_float >= 32)
	{
		type_char =  static_cast<char>(type_float);
		std::cout << "Char: \t'" << type_char << "'" << std::endl;
	}
	else if ((type_float >= 0 && type_float <= 31) || type_float == 127)
		std::cout << "Char: \tNon displayable" << std::endl;
	else
		std::cout << "Char: \timpossible" << std::endl;
	if (type_float > 2147483647.0 || type_float < -2147483648.0)
		std::cout << "Int: \timpossible" << std::endl;
	else
	{
		type_int =  static_cast<int>(type_float);
		std::cout << "Int: \t" << type_int << std::endl;
	}
	type_double =  static_cast<double>(type_float);
	std::cout << "Float: \t" << std::fixed << std::setprecision(1) << type_float << "f" << std::endl;
	std::cout << "Double: " << type_double << std::endl;

	return ;
}

void ScalarConverter::fromDouble()
{
	if (type_double <= 126 && type_double >= 32)
	{
		type_char =  static_cast<char>(type_double);
		std::cout << "Char: \t'" << type_char << "'" << std::endl;
	}
	else if ((type_double >= 0 && type_double <= 31) || type_double == 127)
		std::cout << "Char: \tNon displayable" << std::endl;
	else
		std::cout << "Char: \timpossible" << std::endl;
	if (type_double > 2147483647.0 || type_double < -2147483648.0)
		std::cout << "Int: \timpossible" << std::endl;
	else
	{
		type_int =  static_cast<int>(type_double);
		std::cout << "Int: \t" << type_int << std::endl;
	}
	if (abs(type_double) > FLT_MAX)
		std::cout << "Float: \t" << "impossible"<< std::endl;
	else
	{
		type_float =  static_cast<float>(type_double);
		std::cout << "Float: \t" << std::fixed << std::setprecision(1) << type_float << "f" << std::endl;
	}
	std::cout << "Double: " << static_cast<double>(type_double) << std::endl;
	return ;
}

void ScalarConverter::printPseudos()
{
	std::cout << "Char: \t" << "impossible" << std::endl;
	std::cout << "Int: \t" << "impossible" << std::endl;
	std::cout << "Float: \t" << type_float << "f" << std::endl;
	std::cout << "Double: " << type_double << std::endl;
	return ;
}

const char *ScalarConverter::InvalidType::what() const throw()
{
	return ("Unidentified parameter found\nParameter should be of valid types (INT, CHAR, FLOAT, DOUBLE, PSUEDO)");
}
