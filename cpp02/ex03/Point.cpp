/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:33:08 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 20:20:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::~Point( void )
{
}

Point::Point( const Point& other )
{
	*this = other;
}

Point::Point( const float one, const float two )
{
	this->_x = Fixed(one);
	this->_y = Fixed(two);
}

Point	&Point::operator=( const Point& other )
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}


const Fixed& Point::getX( void ) const { return this->_x; }

const Fixed& Point::getY( void ) const { return this->_y; }

void	Point::setX( const Fixed x ) { this->_x = x; }

void	Point::setY( const Fixed y ) { this->_y = y; }
