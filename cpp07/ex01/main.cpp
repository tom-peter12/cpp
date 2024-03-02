/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:25 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/14 18:35:34 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

int main(void)
{
	std::cout << "Test for an array of int type" << std::endl;
	int			int_arr[5] = { 1, 2, 3, 4, 5 };
	iter(int_arr, 5, display);
	std::cout << std::endl;

	std::cout << "Test for an array of std::string type" << std::endl;
	std::string str_arr[5] = { "A", "B", "C", "D", "E" };
	iter(str_arr, 5, display);
}
