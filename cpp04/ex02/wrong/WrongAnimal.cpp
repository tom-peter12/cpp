/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:54:08 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 23:25:47 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("DefaultWrongAnimal")
{
    std::cout << "🦄: WrongAnimal is created (Default constructor)" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
    std::cout << "🦄: WrongAnimal is created (Copy constructor)" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "🦄: WrongAnimal is destroyed (Default destructor)" << std::endl;
}

WrongAnimal&    WrongAnimal::operator=( const WrongAnimal &other )
{
    std::cout << "🦄: WrongAnimal is assigned (Copy assignment operator)" << std::endl;
    if ( this != &other )
        this->_type = other._type;
    return *this;
}

void    WrongAnimal::setType( std::string type )
{
    if (type.empty())
        type = "DefaultWrongAnimal";
    this->_type = type;
}

std::string const   &WrongAnimal::getType( void ) const { return this->_type; }


void    WrongAnimal::makeSound( void ) const
{
    std::cout << "🦄: WrongAnimal sound" << std::endl;
}

