/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:38:08 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/25 21:19:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook()
{
}

// Default destructor
PhoneBook::~PhoneBook()
{
}

void PhoneBook::print_intro(void)
{
    std::cout << "\033[1;35m";

    std::cout << " _____ ______  ___  ______________   __   ___  _    _ _____ _____  ________  ___ _____  ______ _   _ _____ _   _  ___________  _____  _____ _   __" << std::endl;
    std::cout << "/  __ \\| ___ \\/ _ \\ | ___ \\ ___ \\ \\ / /  / _ \\| |  | |  ___/  ___||  _  |  \\/  ||  ___| | ___ \\ | | |  _  | \\ | ||  ___| ___ \\|  _  ||  _  | | / /" << std::endl;
    std::cout << "| /  \\/| |_/ / /_\\ \\| |_/ / |_/ /\\ V /  / /_\\ \\ |  | | |__ \\ `--. | | | | .  . || |__   | |_/ / |_| | | | |  \\| || |__ | |_/ /| | | || | | | |/ /" << std::endl;
    std::cout << "| |    |    /|  _  ||  __/|  __/  \\ /   |  _  | |/\\| |  __| `--. \\| | | | |\\/| ||  __|  |  __/|  _  | | | | . ` ||  __|| ___ \\| | | || | | |    \\" << std::endl;
    std::cout << "| \\__/\\| |\\ \\| | | || |   | |     | |   | | | \\  /\\  / |___/\\__/ /\\ \\_/ / |  | || |___  | |   | | | \\ \\_/ / |\\  || |___| |_/ /\\ \\_/ /\\ \\_/ / |\\  \\" << std::endl;
    std::cout << " \\____/\\_| \\_\\_| |_/\\_|   \\_|     \\_/   \\_| |_/\\/  \\/\\____/\\____/  \\___/\\_|  |_/\\____/  \\_|   \\_| |_/\\___/\\_| \\_/\\____/\\____/  \\___/  \\___/\\_| \\_/" << std::endl;

    std::cout << "\033[0m";
    std::cout << "\n\033[1;33m[ADD]:\033[0m\t\tTo add new contact \n\033[1;33m[SEARCH]:\033[0m\tTo search for contact\n\033[1;33m[EXIT]:\033[0m\t\tTo exit" << std::endl;
    std::cout << std::endl;
}



void contact_saved(void)
{
    std::cout << "\033[1;32m";
    std::cout << "  .--.--.      ,---,                      ,---,.    ,---,     " << std::endl;
    std::cout << " /  /    '.   '  .' \\            ,---.  ,'  .' |  .'  .' `\\   " << std::endl;
    std::cout << "|  :  /`. /  /  ;    '.         /__./|,---.'   |,---.'     \\  " << std::endl;
    std::cout << ";  |  |--`  :  :       \\   ,---.;  ; ||   |   .'|   |  .`\\  | " << std::endl;
    std::cout << "|  :  ;_    :  |   /\\   \\ /___/ \\  | |:   :  |-,:   : |  '  | " << std::endl;
    std::cout << " \\  \\    `. |  :  ' ;.   :\\   ;  \\ ' |:   |  ;/||   ' '  ;  : " << std::endl;
    std::cout << "  `----.   \\|  |  ;/  \\   \\   \\  \\:  ||   :   .''   | ;  .  | " << std::endl;
    std::cout << "  __ \\  \\  |'  :  | \\  \\ ,' ;   \\  ' .|   |  |-,|   | :  |  ' " << std::endl;
    std::cout << " /  /`--'  /|  |  '  '--'    \\   \\   ''   :  ;/|'   : | /  ;  " << std::endl;
    std::cout << "'--'.     / |  :  :           \\   `  ;|   |    |   | '` ,/   " << std::endl;
    std::cout << "  `--'---'  |  | ,'            :   \\ ||   :   .';   :  .'     " << std::endl;
    std::cout << "            `--''               '---\" |   | ,'  |   ,.'       " << std::endl;
    std::cout << "                                      `----'    '---'         " << std::endl;
    std::cout << "\n                     Successfully Saved!                   \n" << std::endl;
    std::cout << "\033[0m" << std::endl;
}


void PhoneBook::print_outro() 
{
	std::cout << "\033[1;34m";
    std::cout 
        << "   _____                 _   _                _    _____                                  __     __            _____                                                                             _  " << std::endl
        << "  / ____|               | | | |              | |  / ____|                                 \\ \\   / /           / ____|                                 /\\                                        | | " << std::endl
        << " | |  __  ___   ___   __| | | |__  _   _  ___| | | (___   ___  ___   _   _  ___  _   _     \\ \\_/ /__  _   _  | |     _ __ __ _ _ __  _ __  _   _     /  \\__      _____  ___  ___  _ __ ___   ___| | " << std::endl
        << " | | |_ |/ _ \\ / _ \\ / _` | | '_ \\| | | |/ _ \\ |  \\___ \\ / _ \\/ _ \\ | | | |/ _ \\| | | |     \\   / _ \\| | | | | |    | '__/ _` | '_ \\| '_ \\| | | |   / /\\ \\ \\ /\\ / / _ \\/ __|/ _ \\| '_ ` _ \\ / _ \\ | " << std::endl
        << " | |__| | (_) | (_) | (_| | | |_) | |_| |  __/_|  ____) |  __/  __/ | |_| | (_) | |_| |_     | | (_) | |_| | | |____| | | (_| | |_) | |_) | |_| |  / ____ \\ V  V /  __/\\__ \\ (_) | | | | | |  __/_| " << std::endl
        << "  \\_____|\\___/ \\___/ \\__,_| |_.__/ \\__, |\\___(_) |_____/ \\___|\\___|  \\__, |\\___/ \\__,_( )    |_|\\___/ \\__,_|  \\_____|_|  \\__,_| .__/| .__/ \\__, | /_/    \\_\\_/\\_/ \\___||___/\\___/|_| |_| |_|\\___(_) " << std::endl
        << "                                    __/ |                             __/ |           |/                                      | |   | |     __/ |                                                   " << std::endl
        << "                                   |___/                             |___/                                                    |_|   |_|    |___/                                                    " << std::endl;
		std::cout << "\033[0m";
}


std::string trim(std::string str)
{
	std::size_t start = str.find_first_not_of(" \t\n\r\b");
	std::size_t end = str.find_last_not_of(" \t\n\r\b") + 1;

	if (start == std::string::npos)
		return "";
	return (str.substr(start, end));
}

int		PhoneBook::validate_str(std::string inp)
{
	if (inp.empty())
		return (1);
	for (std::string::iterator it = inp.begin(); it != inp.end(); ++it)
	{
		if (!(std::isalpha(*it)))
			return (1);
	}
	return (0);
}

int		PhoneBook::validate_phone(std::string inp)
{
	if (inp.empty())
		return (1);
	for (std::string::iterator it = inp.begin(); it != inp.end(); ++it)
	{
		if (!(std::isdigit(*it)))
			return (1);
	}
	return (0);
}

std::string	PhoneBook::accept_inp(std::string message)
{
	std::string value;
	std::string trimmed_value;
	int			i = 1;
	
	while (i)
	{
		std::cout << std::endl;
		std::cout << message;
		std::getline (std::cin, value);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cin.clear();
			this->print_outro();
			std::exit(EXIT_FAILURE);
			break ;
		}
		trimmed_value = trim(value);
		if (!message.compare("Phone Number: "))
			i = (this->validate_phone(trimmed_value));
		else
			i = (this->validate_str(trimmed_value));
		if (i)
			std::cout << "\033[1;31mPlease Provide Valid Input\033[0m" << std::endl;
	}
	return (value);
}

// Creating and Adding a new contact
void	PhoneBook::add(size_t *index)
{
	std::string fname;
	std::string lname;
	std::string nname;
	std::string phonenum;
	std::string dsecret;
	
	fname = this->accept_inp("First Name: ");
	this->contacts[*index % 8].set_f_name(fname);

	lname = this->accept_inp("Last Name: ");
	this->contacts[*index % 8].set_l_name(lname);
	
	nname = this->accept_inp("Nick Name: ");
	this->contacts[*index % 8].set_n_name(nname);

	phonenum = this->accept_inp("Phone Number: ");
	this->contacts[*index % 8].set_p_number(phonenum);

	dsecret = this->accept_inp("Dark Secret: ");
	this->contacts[*index % 8].set_d_secret(dsecret);
	
	contact_saved();
	(*index)++;
}

int	int_validation(std::string inp)
{
	if (inp.empty())
		return (1);
	if (std::atoi(inp.c_str()) < 0 || std::atoi(inp.c_str()) > 7)
		return (3);
	for (std::string::iterator it = inp.begin(); it != inp.end(); ++it)
	{
		if (!(std::isdigit(*it)))
		{
			std::cout << "\033[1;31mInvalid Index: Please only Integer \033[0m" << std::endl;
			return (4);
		}
	}
	return (0);
}

int	PhoneBook::input_value(void)
{
	std::string	num;
	int		i = 1;

	while (i)
	{
		std::cout << "ENTER INDEX : ";
		std::getline (std::cin, num);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cin.clear();
			this->print_outro();
			std::exit(EXIT_FAILURE);
			break ;
		}
		i = int_validation((num));
		if (i == 3)
			std::cout << "\033[1;31mIndex out of range: \033[0m" << num << std::endl;
	}
	return (atoi(num.c_str()));
}

void	print_indiv(std::string inp)
{
	if (inp.length() > 9)
	{
		std::cout << std::setw(9);
		std::cout << inp.substr(0, 8) << "." << "|" ;
	}
	else
		std::cout << std::setw(10) << std::right << inp << "|" ;
}

std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void	print_message(int i, std::string f_name, std::string l_name, std::string n_name)
{
	std::cout << "|";
	print_indiv(intToString(i));
	print_indiv(f_name);
	print_indiv(l_name);
	print_indiv(n_name);
	std::cout << std::endl;
	std::cout << " ------------------------------------------- ";
	std::cout << std::endl;
}

void PhoneBook::print_contact(int num)
{
    std::cout << "╔═══════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         CONTACT CARD                      ║" << std::endl;
    std::cout << "╠═════════════════╦═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ First Name     :║ " << std::left << std::setw(40) << this->contacts[num].get_f_name() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Last Name      :║ " << std::left << std::setw(40) << this->contacts[num].get_l_name() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Nick Name      :║ " << std::left << std::setw(40) << this->contacts[num].get_n_name() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Phone Number   :║ " << std::left << std::setw(40) << this->contacts[num].get_p_number() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Dark Secret    :║ " << std::left << std::setw(40) << this->contacts[num].get_d_secret() << "║" << std::endl;
    std::cout << "╚═════════════════╩═════════════════════════════════════════╝" << std::endl;
}


int	PhoneBook::print_all()
{
	int	num = 0;
	int ret = 0;

	if ((this->contacts[num].get_f_name().empty()))
	{
		std::cout << "The Phone Book is empty!" << std::endl;
		ret = 1;
	}
	else
	{
		std::cout << " ------------------------------------------- " << std::endl;
		std::cout << "|     Index|" << "First Name|" << " Last Name|" << " Nick Name|" << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
		while (num < 8 && !(this->contacts[num].get_f_name().empty()))
		{
			print_message(num, this->contacts[num].get_f_name(), 
				this->contacts[num].get_l_name(),
				this->contacts[num].get_n_name()
			);
			num++;
		}
	}
	return (ret);
}

// Searching for a contact
void	PhoneBook::search()
{
	int	i = 1;
	if (this->print_all())
		return ;

	while (i)
	{
		int	num = input_value();
		if (!this->contacts[num].get_f_name().empty())
		{
			this->print_contact(num);
			i = 0;
		}
		else
		{
			std::cout << "\033[1;31mContact Doesn't Exist at Index: \033[0m" << num << std::endl;
		}
	}
}
