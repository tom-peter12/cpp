/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 20:21:10 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed( void )
{
	this->_fixed_point_value = 0;
}


Fixed::~Fixed( void )
{
}


Fixed::Fixed( const Fixed& other)
{
	*this = other;
}


Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point_value = other._fixed_point_value;
	return *this;
}


Fixed::Fixed( const int param )
{
	this->_fixed_point_value = param << this->_fractional_bits;
}

Fixed::Fixed( const float param )
{
	this->_fixed_point_value = roundf(param * (1 << this->_fractional_bits));
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed_point_value >> this->_fractional_bits);
}


int		Fixed::getRawBits( void ) const { return (this->_fixed_point_value); }

void 	Fixed::setRawBits( int const raw ) { this->_fixed_point_value = raw; }


std::ostream 	&operator<<(std::ostream& COUT, const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}


bool	Fixed::operator>(const Fixed& other)
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (this->getRawBits() != other.getRawBits());
}





Fixed	Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}


Fixed	Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/*
	# ++ and -- operators
	  - (void) preincrement and predecrement operators
	  - (int) postincrement and postdecrement operators
*/

Fixed	&Fixed::operator++(void)
{
	this->_fixed_point_value++;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed_point_value--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixed_point_value++;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixed_point_value--;
	return tmp;
}






Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	return (one < two ? one : two);
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one.toFloat() < two.toFloat())
		return (one);
	return (two);
}


Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	return (one > two ? one : two);
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one.toFloat() > two.toFloat())
		return (one);
	return (two);
}

