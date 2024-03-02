/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:42:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/02 15:36:46 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"


std::string    Brain::conv(int value)
{
    std::stringstream ss;
    ss << value;

    return ss.str();
}

Brain::Brain( void )
{
    std::cout << "🧠: Brain is created (Default constructor)" << std::endl;
    for ( int i = 0; i < 100; i++ )
        this->_ideas[i] = "Default idea #" + conv(i);
}

Brain::~Brain( void )
{
    std::cout << "🧠: Brain is destroyed (Default destructor)" << std::endl;
}

Brain::Brain( const Brain &other )
{
    std::cout << "🧠: Brain is created (Copy constructor)" << std::endl;
    *this = other;
}

Brain&  Brain::operator=( const Brain &other )
{
    std::cout << "🧠: Brain is created (Copy assignment operator)" << std::endl;
    if ( this != &other )
    {
        for ( int i = 0; i < 100; i++ )
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

void    Brain::setIdea( std::string idea, unsigned int index )
{
    if ( index < 100 )
        this->_ideas[index] = idea;
    
}


const std::string&     Brain::getIdea( unsigned int index ) const
{
    if (index < 100)
        return this->_ideas[index];
    else
    {
        std::cout << "🧠: Brain ideas out of index" << std::endl;
        return this->_ideas[0];
    }
}

