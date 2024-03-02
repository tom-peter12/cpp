/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:25:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/30 23:45:18 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_forms[0] = "presidential pardon";
	_forms[1] = "robotomy request";
	_forms[2] = "shrubbery creation";
	_makeForm[0] = &Intern::makePresidentialPardonForm;
	_makeForm[1] = &Intern::makeRobotomyRequestForm;
	_makeForm[2] = &Intern::makeShrubberyCreationForm;
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
			form = (this->*_makeForm[i])(target);
	}
	if (form == NULL)
		throw (Intern::UnkownFormGiven());
	return (form);
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	std::cout << "Intern creates " << target << " Presidential Pardon Form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	std::cout << "Intern creates " << target << " Robotomy Form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
	std::cout << "Intern creates " << target << " Shrubery form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

const char* Intern::UnkownFormGiven::what() const throw()
{
	return ("Intern::UnkownFormGiven");
}
