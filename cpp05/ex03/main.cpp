/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:13:19 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/08 15:37:21 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:23:49 by lle-briq          #+#    #+#             */
/*   Updated: 2022/03/24 14:23:25 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int	main(void)
{
	Bureaucrat	ceo("CEO", 1);
	Intern		exploitedIntern;
	AForm		*forms[4];


	try
	{
		forms[0] = exploitedIntern.makeForm("shrubbery creation", "Target1");
		forms[1] = exploitedIntern.makeForm("robotomy request", "Target2");
		forms[2] = exploitedIntern.makeForm("presidential pardon", "Target3");
		// forms[3] = exploitedIntern.makeForm("formular", "Target4");
		for (int i = 0; i < 4; i++)
		{
			if (forms[i])
			{
				std::cout << std::endl << *(forms[i]);
				ceo.signForm(*(forms[i]));
				ceo.executeForm(*(forms[i]));
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what()  << '\n';
	}

	for (int i = 0; i < 3; i++)
		delete forms[i];
	return (0);
}