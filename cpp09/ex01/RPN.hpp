/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:04 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/17 15:27:36 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <exception>
# include <cstring>


class RPN
{
	private:
		static std::stack<int> _rpn_stack;


		RPN( void );
		~RPN( void );
		RPN( const RPN& src );
		RPN& operator=( const RPN& rhs );


	public:
		static int do_rpn( const std::string& ops );

		class NotEnoughOperators : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughOperands : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidCharacterInOperands : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};