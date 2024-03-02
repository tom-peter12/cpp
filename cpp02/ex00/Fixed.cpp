/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:16:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 18:29:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

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
		this->_fixed_point_value = other.getRawBits();
	return *this;
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
