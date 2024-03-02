/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:17:06 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 20:19:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"

static std::string	toString(int e)
{
	if (e)
		return (("true"));
	else
		return ("false");
}

int main( void ) 
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point p(2, 2);
	
	std::cout << toString(bsp(a, b, c, p)) << std::endl;
	
	return 0;
}
