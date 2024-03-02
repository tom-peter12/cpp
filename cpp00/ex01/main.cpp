/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:35:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/25 17:10:09 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"


int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;
	size_t		index = 0;

	phonebook.print_intro();
	while (true)
	{
		std::cout << "Enter your operation: ";
		std::getline (std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << std::endl;
			break ;
		}
		if (!(command.compare("ADD")))
			phonebook.add(&index);
		else if (!(command.compare("SEARCH")))
			phonebook.search();
		else if (!(command.compare("EXIT")))
			break ;
	}
	phonebook.print_outro();
	return (0);
}
