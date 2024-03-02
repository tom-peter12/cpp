/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:06:17 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 23:27:35 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
    std::cout << "😾: WrongCat is created (Default constructor)" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other)
{
    std::cout << "😾: WrongCat is created (Copy constructor)" << std::endl;
    *this = other;
}

WrongCat::~WrongCat( void )
{
    std::cout << "😾: WrongCat is destroyed (Default destructor)" << std::endl;
}

WrongCat&    WrongCat::operator=( const WrongCat &other )
{
    std::cout << "😾: WrongCat is created (Copy assignment operator)" << std::endl;
    if ( this != &other )
        this->_type = other._type;
    return *this;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "😾: says \"Meow!\"" << std::endl;
}
