/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:41:08 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 15:21:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl( void )
{
}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}


void    Harl::complain( std::string level )
{
    void    (Harl::*ptrfn[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    
    int found = 0;
    
    for ( int i = 0; i < 4; i++ )
    {
        while ( levels[i] == level )
        {
            switch (i)
            {
                case 0: case 1: case 2: case 3:
                {
                    found = 1;
                    while (i < 4)
                    {
                        std::cout << "[ " << levels[i] << " ]" << std::endl;
                        (this->*ptrfn[i])();
                        i++;
                        std::cout << std::endl;
                    }
                    break;
                }
            }
            i++;
        }
    }
    switch (found)
    {
        case 0:
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
        
        default:
            break;
    }
}

