/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:36:31 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/19 22:12:22 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	try 
	{
		PmergeMe::parse(ac, av);
		PmergeMe::compare();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}