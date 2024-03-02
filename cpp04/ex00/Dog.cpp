/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:55:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/01 16:40:58 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
    std::cout << "🐶: Dog is created (Default constructor)" << std::endl;
    this->_type = "Dog";
}

Dog::Dog( const Dog &other ) : Animal(other)
{
    std::cout << "🐶: Dog is created (Copy constructor)" << std::endl;
    *this = other;
}

Dog::~Dog( void )
{
    std::cout << "🐶: Dog is destroyed (Default destructor)" << std::endl;
}

Dog&    Dog::operator=( const Dog &other )
{
    std::cout << "🐶: Dog is created (Copy assignment operator)" << std::endl;
	if ( this != &other )
    	this->_type = other._type;
    return *this;
}

void    Dog::makeSound( void ) const
{
    std::cout << "🐶: Dog says \"Woof!\"" << std::endl;
}
