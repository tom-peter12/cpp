/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:42:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/11 12:27:09 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

float	area( Point const a, Point const b, Point const c )
{
	float	ab;
	float	bc;
	float	ac;
	float	s;

	ab = sqrt(pow((b.getX() - a.getX()).toFloat(), 2) + pow((b.getY() - a.getY()).toFloat(), 2));
	bc = sqrt(pow((c.getX() - b.getX()).toFloat(), 2) + pow((c.getY() - b.getY()).toFloat(), 2));
	ac = sqrt(pow((c.getX() - a.getX()).toFloat(), 2) + pow((c.getY() - a.getY()).toFloat(), 2));
	s = (ab + bc + ac) / 2;
	return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	abc;
	float	abp;
	float	acp;
	float	bcp;

	abc = area(a, b, c);
	abp = area(a, b, point);
	acp = area(a, c, point);
	bcp = area(b, c, point);
	if (abc == abp + acp + bcp)
		return true;
	return false;
}