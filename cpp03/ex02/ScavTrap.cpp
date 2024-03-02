/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:39:26 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 21:29:43 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_maxHitPoints = this->_hitPoints;
    std::cout << "💻: ScavTrap is created (Default constructor)" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "💻 -> 💀: ScavTrap is destroyed (Default destructor)!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap( other )
{
    *this = other;
    std::cout << "💻: ScavTrap is created (Copy constructor)" << std::endl;
}

ScavTrap    &ScavTrap::operator=( ScavTrap const &other )
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        this->_maxHitPoints = other._hitPoints;
    }
    std::cout << "💻: ScavTrap is created (Assignment operator overload)" << std::endl;
    return *this;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_maxHitPoints = this->_hitPoints;
    std::cout << "💻: ScavTrap is created (Parameterized constructor)" << std::endl;
}

void    ScavTrap::attack( const std::string& target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "💻: ScavTrap : \"" << this->_name << "\" attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "💻: ScavTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has no energy points left." << std::endl;
	else
		std::cout << "💻: ScavTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has not enough hit points." << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "💻: ScavTrap is now in Gate keeper mode" << std::endl;
}


