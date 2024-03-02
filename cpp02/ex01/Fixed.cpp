/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 18:36:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/**
 * @brief Methods for converting between floating-point and fixed-point numbers and integers.
 *
 * Fixed-Point Conversion Formulas:
 * 
 * 1. Float to Fixed-Point:
 *    To convert a floating-point number floatNum to a fixed-point representation 
 *    with F fractional bits:
 *    - fixedNum = round(floatNum * 2^F)
 *    Using bit-shifting, this can be implemented as:
 *    - fixedNum = round(floatNum) << F
 * 
 * 2. Fixed-Point to Float:
 *    To convert a fixed-point number fixedNum with F fractional bits back 
 *    to its floating-point representation:
 *    - floatNum = fixedNum / 2^F
 *    Using bit-shifting, this is equivalent to:
 *    - floatNum = fixedNum / (float)(1 << F)
 * 
 * 3. Integer to Fixed-Point:
 *   To convert an integer intNum to a fixed-point representation with F fractional bits:
 *    - fixedNum = intNum << F
 * 
 * 4. Fixed-Point to Integer:
 *   To convert a fixed-point number fixedNum with F fractional bits back to an integer:
 *    - intNum = fixedNum >> F
 *
 * Note: The number of fractional bits, F, determines the precision of the 
 * fixed-point representation. 
 */


int const Fixed::_fractional_bits = 8;

Fixed::Fixed( void )
{
	this->_fixed_point_value = 0;
	std::cout << "Fixed point created (Default constructor)" << std::endl;
}


Fixed::~Fixed( void )
{
	std::cout << "Fixed point destroyed (Default destructor)" << std::endl;
}


Fixed::Fixed( const Fixed& other)
{
	std::cout << "Fixed point created (Copy constructor)" << std::endl;
	*this = other;
}


Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Fixed point created (Copy assignment operator)" << std::endl;
	if (this != &other)
		this->_fixed_point_value = other._fixed_point_value;
	return *this;
}


Fixed::Fixed( const int param )
{
	this->_fixed_point_value = param << this->_fractional_bits;
	std::cout << "Fixed point created (Integer constructor)" << std::endl;
}

Fixed::Fixed( const float param )
{
	this->_fixed_point_value = roundf(param * (1 << this->_fractional_bits));
	std::cout << "Fixed point created (Float constructor)" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed_point_value >> this->_fractional_bits);
}


int	Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called!" << std::endl;
	return (this->_fixed_point_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_point_value = raw;
}


std::ostream 	&operator<<(std::ostream& COUT, const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}
