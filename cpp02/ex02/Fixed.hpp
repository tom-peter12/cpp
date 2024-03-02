/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 20:06:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <climits>
# include <iomanip>


class Fixed
{
	private:
		int							_fixed_point_value;
		static const int		 	_fractional_bits;

	public:

		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &other );
		Fixed	&operator=( const Fixed &other);

		Fixed( const int param );
		Fixed( const float param );
		
		
		int 						getRawBits( void ) const;
		void 						setRawBits( int const raw );

		float						toFloat( void ) const;
		int							toInt( void ) const;

		bool						operator>(const Fixed& other);
		bool						operator<(const Fixed& other);
		bool						operator>=(const Fixed& other);
		bool						operator<=(const Fixed& other);
		bool						operator==(const Fixed& other);
		bool						operator!=(const Fixed& other);

		Fixed						operator+(const Fixed& other) const;
		Fixed						operator-(const Fixed& other) const;
		Fixed						operator*(const Fixed& other) const;
		Fixed						operator/(const Fixed& other) const;

		Fixed&						operator++(void);
		Fixed&						operator--(void);
		Fixed						operator++(int);
		Fixed						operator--(int);


		static Fixed&				min(Fixed& one, Fixed& two);
		static const Fixed&			min(const Fixed& one, const Fixed& two);
		static Fixed&				max(Fixed& one, Fixed& two);
		static const Fixed&			max(const Fixed& one, const Fixed& two);
		
		
};



std::ostream 	&operator<<(std::ostream& COUT, const Fixed& fixed);

# endif
