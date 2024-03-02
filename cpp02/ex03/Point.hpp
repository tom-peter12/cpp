/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:30:02 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 20:14:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed		_x;
		Fixed		_y;
	
	public:
		Point( void );
		Point( const Point& other );
		Point( const float one, const float two );
		Point	&operator=(const Point& other );
		~Point( void );

		const Fixed&	getX( void ) const;
		const Fixed&	getY( void ) const;
		void	setX( const Fixed x );
		void	setY( const Fixed y );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

# endif
