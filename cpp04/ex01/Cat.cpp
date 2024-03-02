/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:38:09 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/02 15:48:53 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Cat.hpp"


Cat::Cat( void ) : Animal()
{
    std::cout << "🐈: Cat is created (default constructor)" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    for ( int i = 0; i < 100; i++ )
        this->_brain->setIdea("Cat idea #" + (Brain::conv(i)), i);
}

Cat::Cat( const Cat &other ) : Animal(other)
{
    std::cout << "🐈: Cat is created (copy constructor)" << std::endl;
    *this = other;
}

Cat::~Cat( void )
{
    std::cout << "🐈: Cat is destroyed (default destructor)" << std::endl;
    delete this->_brain;
}

Cat&    Cat::operator=( const Cat &other )
{
    std::cout << "🐈: Cat is created (assignation operator)" << std::endl;
    if ( this != &other )
    {
        this->_type = other._type;
        this->_brain = new Brain();
        for ( int i = 0; i < 100; i++ )
            this->_brain->setIdea(other._brain->getIdea(i), i);
    }
    return *this;
}

void    Cat::makeSound( void ) const
{
    std::cout << "🐈: says \"Meow!\"" << std::endl;
}

Brain   *Cat::getBrain( void ) const
{
    return this->_brain;
}

