/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:13:19 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/05 21:13:51 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "\033[33m" <<std::string(110, '-') << "\033[0m" << std::endl;
	{

		std::cout << "\033[33mConstructing\033[0m" << std::endl;
		Bureaucrat b1("Tomas", 150);
		Bureaucrat b2("Stewie", 80);
		Bureaucrat b3("Captain Peter", 2);
		ShrubberyCreationForm f1("shur");
		RobotomyRequestForm f2("robo");
		PresidentialPardonForm f3("quigmaire");

		std::cout << "------------ TEST - 1 ------------" << std::endl;
		try
		{
			// SHRUBBERY
			b1.executeForm(f1);
			b1.incrementGrade(60);
			b1.signForm(f1);
			b1.signForm(f1);
			b1.executeForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "------------ END TEST - 1 ------------" << std::endl << std::endl << std::endl;

		std::cout << "------------ TEST - 2 ------------" << std::endl;
		try
		{
			// ROBOTOMY
			b2.signForm(f2);
			b2.incrementGrade(40);
			b2.signForm(f2);
			b2.executeForm(f2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "------------ END TEST - 2 ------------" << std::endl << std::endl;
		
		std::cout << "------------ TEST - 3 ------------" << std::endl;
		try
		{
			// PRESIDENTIAL
			b3.signForm(f3);
			b3.executeForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "------------ END TEST - 3 ------------" << std::endl << std::endl;
	}
	return (0);
}