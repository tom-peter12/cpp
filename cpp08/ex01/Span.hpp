/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:23:30 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/15 16:39:08 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <exception>
# include <limits>
# include <ctime>

class Span
{
	private:

		size_t				_size;
		std::vector<int>	_nums;
		
		Span( void );

	public:
		~Span( void );
		Span( const Span& src);
		Span& operator=( const Span& rhs );
		
		Span( size_t N);

		void	addNumber( int num );

		size_t	shortestSpan( void );
		size_t	longestSpan( void );

		void	fillSpan( std::vector<int>::iterator& begin, std::vector<int>::iterator& end );

		const std::vector<int>&	getNums( void ) const;

		class InsertionAtOutOfBound : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class EmptyOrLessElementsToSpan : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& COUT, const Span& sp);