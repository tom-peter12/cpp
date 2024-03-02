/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 18:32:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

/**
 * @class Fixed
 * @brief Represents a fixed-point number.
 * 
 * The Fixed class provides basic functionality for creating, copying, 
 * and assigning fixed-point numbers. It also allows for direct access 
 * and manipulation of its raw integer representation.
 * 
 * Private Members:
 *   - _fixed_point_value: Holds the actual value of the fixed-point number as an integer.
 *   - _fractional_bits: Number of fractional bits used for the fixed-point representation. Default is 8.
 * 
 * Constructors and Destructor:
 *   - Fixed(): Default constructor. Initializes the fixed-point number to a default value.
 *   - ~Fixed(): Destructor. Cleans up any resources if necessary.
 *   - Fixed(const Fixed &other): Copy constructor. Initializes from another Fixed object.
 * 
 * Operator Overloads:
 *   - Fixed &operator=(const Fixed &other): Copy assignment operator. Assigns from another Fixed object.
 * 
 * Member Functions:
 *   - int getRawBits(void) const: Returns the raw integer representation of the fixed-point number.
 *   - void setRawBits(int const raw): Sets the raw integer representation of the fixed-point number.
 */

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


		int 						getRawBits( void ) const;
		void 						setRawBits( int const raw );
};

# endif
