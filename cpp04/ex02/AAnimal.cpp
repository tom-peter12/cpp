/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:34:53 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/02 16:27:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
    std::cout << "🦖: AAnimal created (default constructor)" << std::endl;
}

AAnimal::AAnimal( const AAnimal &other )
{
    std::cout << "🦖: AAnimal created (copy constructor)" << std::endl;
    *this = other;
}

AAnimal&    AAnimal::operator=( const AAnimal &other )
{
    std::cout << "🦖: AAnimal assigned (assignment operator)" << std::endl;
    if ( this != &other )
        this->_type = other._type;
    return *this;
}

AAnimal::~AAnimal( void )
{
    std::cout << "🦖: AAnimal destroyed (default destructor)" << std::endl;
}


void    AAnimal::setType( std::string type )
{
    if (type.empty())
        type = "DefaultAnimal";
    this->_type = type;
}

std::string  const   &AAnimal::getType( void ) const { return this->_type; }

