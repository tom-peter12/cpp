/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 19:42:10 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <climits>


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
};



std::ostream 	&operator<<(std::ostream& COUT, const Fixed& fixed);

# endif
