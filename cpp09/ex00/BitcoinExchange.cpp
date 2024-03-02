/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:44:42 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/22 20:40:36 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

std::map< time_t, double > BitcoinExchange::_database;

double BitcoinExchange::value_to_double(const std::string& value)
{
    char* end;
    double num = strtod(value.c_str(), &end);

    if (end == value.c_str() || *end != '\0' || errno == ERANGE) return (-1);
		
	if (num < 0)
		return (-2);
    return (num);
}


bool BitcoinExchange::check_leap_year(size_t year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	return false;
}

bool BitcoinExchange::check_valid_date(int year, int month, int day)
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && check_leap_year(year))
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}


time_t BitcoinExchange::strtotime(const std::string &s) 
{
    std::tm t = {};
    std::istringstream ss(s);
    char delm;
    int year, month, day;

    if (ss >> year >> delm >> month >> delm >> day && delm == '-' && 
        check_valid_date(year, month, day))
	{
        t.tm_year = year - 1900;
		if (year > 2024 || year < 2009)
			return (static_cast<time_t>(-1));
        t.tm_mon = month - 1;
        t.tm_mday = day;
        return std::mktime(&t);
    }
    return (static_cast<time_t>(-1));
}

int		BitcoinExchange::LoadDataBase( void )
{
	std::ifstream	infile;
	std::string		line_buffer;
	size_t			i;
	int 			end;

	infile.open("data.csv", std::ifstream::in);

	if (!infile.is_open())
	{
		std::cout << "Error: InFile failed to be opened." << std::endl;
		return (-1);
	}

	i = 0;
	while (std::getline(infile, line_buffer))
	{
		if (i != 0)
		{
			end = line_buffer.find(',');
			_database.insert(std::make_pair(strtotime(line_buffer.substr(0, end)), strtod((line_buffer.substr(end + 1, line_buffer.size())).c_str(), NULL)));
		}
		i++;
	}
	infile.close();
	return (0);
}

int		BitcoinExchange::validate_txt( std::string& filename )
{
	int	end;

	end = filename.find('.');
	
	if (filename.substr(end + 1, filename.size()) != "txt")
	{
		std::cout << "Error: Unsupported File Type" << "\n";
		return (-1);
	}
	return (0);
}

std::string BitcoinExchange::trim(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (isspace(*it) || *it == '\t'))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && (isspace(*rit) || *rit == '\t'))
        rit++;

    return std::string(it, rit.base());
}

time_t BitcoinExchange::findClosestKey(const std::map<time_t, double>& map, time_t targetKey)
{
    std::map<time_t, double>::const_iterator it = map.begin();
    std::map<time_t, double>::const_iterator prev_it = it;
    time_t closestKey = it->first;

    for (; it != map.end(); ++it)
	{
        time_t currentKey = it->first;

        if ( currentKey >= targetKey )
		{
            time_t diffWithCurrent = std::abs(static_cast<long>(targetKey - currentKey));
            time_t diffWithPrev = (it == map.begin()) ? diffWithCurrent : std::abs(static_cast<long>(targetKey - prev_it->first));

            if ( diffWithPrev < diffWithCurrent )
                closestKey = prev_it->first;
            else
                closestKey = currentKey;
            break;
        }
        prev_it = it;
    }
    if (it == map.end())
        closestKey = prev_it->first;
    return (closestKey);
}

int	BitcoinExchange::check_line( const std::string& temp, const std::string* h )
{
	std::string::difference_type n = std::count(temp.begin(), temp.end(), '.');
	std::string::difference_type m = std::count(temp.begin(), temp.end(), '|');

	if (n > 1 || m > 1)
	{
		std::cout << "Error: bad input => " << trim(h[0]) << std::endl;
		return (1);
	}
	std::string tempp = trim(h[0]);
	std::string temppp = trim(h[1]);
	for (std::string::const_iterator it = tempp.begin(); it != tempp.end(); ++it)
	{
		if (!std::strchr("0123456789-", *it))
		{
			std::cout << "Error: bad input => " << trim(h[0]) << std::endl;
			return (1);
		}
	}
	for (std::string::const_iterator it = temppp.begin(); it != temppp.end(); ++it)
	{
		if (!std::strchr("0123456789-.", *it))
		{
			std::cout << "Error: bad input => " << trim(h[0]) << std::endl;
			return (1);
		}
	}
	return (0);
}

std::string correctDateFormat(const std::string& date)
{
    std::string result;
    std::string temp;
    std::istringstream stream(date);
    
    getline(stream, temp, '-');
    result += temp;
	for (int i = 0; i < 2; i++)
	{
		if (getline(stream, temp, '-'))
		{
			result += '-';
			if (temp.length() == 1)
				result += '0';
			result += temp;
		}
	}
    for (size_t i = 0; i < result.length(); )
	{
        if (result[i] == ' ' || result[i] == '\t') {
            result.erase(i, 1);
        } else
            ++i;
    }
    return (result);
}



int BitcoinExchange::process_txt( std::string& filename )
{
	std::ifstream	infile;
	std::string		line_buffer;
	int				i;
	int				size;
	double 			value;

	infile.open(filename.c_str(), std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "Error: InFile failed to be opened." << std::endl;
		return (-1);
	}

	i = 0;
	while (std::getline(infile, line_buffer))
	{
		if (line_buffer == "")
			continue;
		
		std::string* h = split(line_buffer, '|', size);
		if (i == 0)
		{
			if (trim(h[0]) == "date" && trim(h[1]) == "value")
			{
				i++;
				delete[] h;
				continue ;
			}
			else
			{
				std::cerr << "Missing or Invalid Format for Header" << std::endl;
				delete[] h;
				return (-1);
			}
		}
		if ( i != 0)
		{
			if (size < 2)
			{
				std::cout << "Error: bad input => " << correctDateFormat(h[0]) << std::endl;
				delete[] h;
				continue ;	
			}
			value = value_to_double(trim(h[1]));
			if (value == -1)
			{
				std::cout << "Error: bad input => " << correctDateFormat(h[0]) << std::endl;
				delete [] h;
				continue ;
			}
			if (check_line(line_buffer, h))
			{
				delete [] h;
				continue ;
			}
			if (value == -2)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000.0)
				std::cout << "Error: too large a number." << std::endl;
			else
			{
				time_t hold = strtotime(correctDateFormat(h[0]));
				if (hold == -1)
				{
					std::cout << "Error: bad input => " << correctDateFormat(h[0]) << std::endl;
					delete [] h;
					continue ;
				}
				time_t m = findClosestKey(_database, hold);
				std::cout << trim(correctDateFormat(h[0])) << " => "<< trim(h[1]) << " = " << (_database.find(m)->second * value) << std::endl;
			}
		}
		i = 1;
		delete[] h;
	}
	return (0);
}


int		BitcoinExchange::bitexchange( std::string filename )
{
	if ( validate_txt( filename ) )
		return (-1);
	
	if (LoadDataBase(  ))
		return (-1);

	if (process_txt( filename ))
		return (-1);
	return (0);
}

std::string* BitcoinExchange::split(const std::string& t, char delm, int& outSize)
{
    std::stringstream ss(t);
    std::string token;

    int count = 0;
    while (std::getline(ss, token, delm))
        count++;
    ss.clear();
    ss.str(t);

    std::string* splitted = new std::string[count];
    outSize = count;

    int index = 0;
    while (std::getline(ss, token, delm))
        splitted[index++] = token;

    return (splitted);
}
