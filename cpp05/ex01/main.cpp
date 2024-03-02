/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:38 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/08 14:17:57 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"


int main(void)
{

	std::cout << "\033[33m" <<std::string(110, '-') << "\033[0m" << std::endl;
	{

		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		
		Bureaucrat	assistant("Assistant", 145);
		Bureaucrat	themainman("CEO", 1);
		Form		form("Rent Contract", 140, 100);
		
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << assistant << std::endl;
		std::cout << themainman << std::endl;
		std::cout << form << std::endl;

		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
		try
		{
			assistant.signForm(form);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}

		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;

		try
		{
			themainman.signForm(form);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
		std::cout << form << std::endl;

		std::cout << "\033[33m" <<std::string(110, '-') << "\033[0m" << std::endl << std::endl;
	}
	return (0);
}