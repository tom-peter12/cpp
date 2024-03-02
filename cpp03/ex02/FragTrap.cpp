/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:01:09 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 21:40:12 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
    this->_name = "Fragtrappington";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_maxHitPoints = this->_hitPoints;
    std::cout << "🐸: FragTrap is created (Default constructor)" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_maxHitPoints = this->_hitPoints;
    std::cout << "🐸: FragTrap is created (Parameterized constructor)" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "🐸 -> 💀: FragTrap is destroyed (Default destructor)" << std::endl;
}

FragTrap::FragTrap( const FragTrap & other ) : ClapTrap( other )
{
    *this = other;
    std::cout << "🐸: FragTrap is created (Copy constructor)" << std::endl;
}

FragTrap    &FragTrap::operator=( const FragTrap & other )
{
    std::cout << "🐸: FragTrap is created (Copy assignment operator)" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        this->_maxHitPoints = other._maxHitPoints;
    }
    return (*this);
}


void    FragTrap::highFivesGuys( void )
{
    std::cout << "🐸: FragTrap : Sup suckers! High Five!" << std::endl;
}

void    FragTrap::attack( const std::string& target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "🐸: FragTrap : \"" << this->_name << "\" attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "🐸: FragTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has no energy points left." << std::endl;
	else
		std::cout << "🐸: FragTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has not enough hit points." << std::endl;
}
