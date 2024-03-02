/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:51 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/10 13:55:03 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP


# include <iostream>
# include <string>
# include <cmath>
# include <limits.h>
# include <cfloat>
# include <ostream>
# include <stdlib.h>
# include <iomanip>
# include <exception>

typedef enum e_types
{
	TYPE_CHAR = 0,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDOS
}	t_types;

class ScalarConverter
{
	private:

		static int		type;
		static char		type_char;
		static int		type_int;
		static float	type_float;
		static double	type_double;

		static int		parseString(std::string &toConvert);
		static int		pseudoLiterals(std::string &toConvert);
		static int		single(std::string &toConvert);

		static int		checkInt(std::string &toConvert);	
		static int		checkFloat(std::string &toConvert);
		static int		checkDouble(std::string &toConvert);

		static void		printPseudos(void);

		static void		fromChar(void);
		static void		fromInt(void);
		static void		fromFloat(void);
		static void		fromDouble(void);

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);

	public:

		static void	convert(std::string toConvert);

		class InvalidType : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};


# endif
