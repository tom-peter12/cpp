/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:44:56 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/12 21:26:09 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (BitcoinExchange::bitexchange(argv[1]))
			return (-1);
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	return (0);
}