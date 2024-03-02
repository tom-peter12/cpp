/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:34:53 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 23:13:16 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal( void ) : _type("DefaultAnimal")
{
    std::cout << "🦖: Animal is created (default constructor)" << std::endl;
}

Animal::Animal( const Animal &other )
{
    std::cout << "🦖: Animal is created (copy constructor)" << std::endl;
    *this = other;
}

Animal::~Animal( void )
{
    std::cout << "🦖: Animal is destroyed (default destructor)" << std::endl;
}

Animal&    Animal::operator=( const Animal &other )
{
    std::cout << "🦖: Animal is assigned (assignment operator)" << std::endl;
    if ( this != &other )
        this->_type = other._type;
    return *this;
}

void    Animal::setType( std::string type )
{
    if (type.empty())
        type = "DefaultAnimal";
    this->_type = type;
}

std::string  const   &Animal::getType( void ) const { return this->_type; }


void    Animal::makeSound( void ) const
{
    std::cout << "🦖: Animal sound" << std::endl;
}

