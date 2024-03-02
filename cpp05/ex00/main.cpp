/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:38 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/08 14:16:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "------------ TEST - 1 ------------" << std::endl;
	{
		try
		{
			Bureaucrat	bureau("tomas", 75);
			for (int i = 0; i < 76; i++)
			{
				std::cout << bureau	<< std::endl;
				bureau.decrementGrade(10);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "------------ TEST - 2 ------------" << std::endl;
	{
		try
		{
			Bureaucrat	bureau("tomas", -75);
			for (int i = 0; i < 76; i++)
			{
				std::cout << bureau	<< std::endl;
				bureau.decrementGrade(10);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
