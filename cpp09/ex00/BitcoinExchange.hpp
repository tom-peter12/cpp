/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:44:59 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/20 18:57:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <map>
# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <fstream>
# include <exception>
# include <iomanip>
# include <sstream>
# include <list>
# include <algorithm>

class BitcoinExchange
{
	private:
		
		static std::map< time_t, double > _database;

		static int	LoadDataBase( void );
		static time_t strtotime( const std::string & s );

		
		static int	validate_txt( std::string& filename );
		static int	process_txt( std::string& filename );
		static std::string* split( const std::string& t, char delm, int& outSize );
		static bool check_leap_year(size_t year);
		static bool check_valid_date(int year, int month, int day);
		static double value_to_double(const std::string& value);
		static std::string trim(const std::string &s);
		static time_t findClosestKey(const std::map<time_t, double>& map, time_t targetKey);

		static int	check_line( const std::string& temp, const std::string* h );

		BitcoinExchange( void );
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& src );
		BitcoinExchange& operator=( const BitcoinExchange& rhs );
		
	public:
		
		static int	bitexchange( std::string filename );
		
};

