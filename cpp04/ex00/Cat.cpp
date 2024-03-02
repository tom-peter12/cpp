/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:38:09 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/02 15:46:40 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
    std::cout << "🐈: Cat is created (default constructor)" << std::endl;
    this->_type = "Cat";
}

Cat::Cat( const Cat &other ) : Animal(other)
{
    std::cout << "🐈: Cat is created (copy constructor)" << std::endl;
    *this = other;
}

Cat::~Cat( void )
{
    std::cout << "🐈: Cat is destroyed (default destructor)" << std::endl;
}

Cat&    Cat::operator=( const Cat &other )
{
    std::cout << "🐈: Cat is created (assignation operator)" << std::endl;
    if ( this != &other )
        this->_type = other._type;
    return *this;
}

void    Cat::makeSound( void ) const
{
    std::cout << "🐈: says \"Meow!\"" << std::endl;
}
