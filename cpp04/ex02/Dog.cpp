/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:55:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/28 00:37:55 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog( void ) : AAnimal()
{
    std::cout << "🐶: Dog is created (Default constructor)" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea("Dog idea #" + std::string(Brain::conv(i)), i);
}

Dog::Dog( const Dog &other ) : AAnimal(other)
{
    std::cout << "🐶: Dog is created (Copy constructor)" << std::endl;
    *this = other;
}

Dog::~Dog( void )
{
    std::cout << "🐶: Dog is destroyed (Default destructor)" << std::endl;
    delete this->_brain;
}

Dog&    Dog::operator=( const Dog &other )
{
    std::cout << "🐶: Dog is created (Copy assignment operator)" << std::endl;
    if ( this != &other )
    {
        this->_type = other._type;
        this->_brain = new Brain();
        for ( int i = 0; i < 100; i++ )
            this->_brain->setIdea(other._brain->getIdea(i), i);        
    }
    return *this;
}

void    Dog::makeSound( void ) const
{
    std::cout << "🐶: Dog says \"Woof!\"" << std::endl;
}


Brain   *Dog::getBrain( void ) const
{
    return this->_brain;
}
