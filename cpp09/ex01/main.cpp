/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:49 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/17 15:28:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (-1);
	}
	try
	{
		std::cout << RPN::do_rpn(std::string(argv[1])) << std::endl;
	}
	catch ( const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	return (0);
}