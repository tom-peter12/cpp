/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:51:16 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/01 14:56:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "DiamonTrappington";
	this->ClapTrap::_name = ClapTrap::_name + "_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
    std::cout << "💎: DiamondTrap is created (Default constructor)" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "💎 -> 💀: DiamondTrap is destroyed (Default destructor)" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & other ) : ClapTrap( other ), ScavTrap( other ), FragTrap( other )
{
    *this = other;
    std::cout << "💎: DiamondTrap is created (Copy constructor)" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->ClapTrap::_hitPoints = other.ClapTrap::_hitPoints;
        this->ScavTrap::_energyPoints = other.ScavTrap::_energyPoints;
        this->FragTrap::_attackDamage = other.FragTrap::_attackDamage;
        this->_maxHitPoints = other._maxHitPoints;
    }
    std::cout << "💎: DiamondTrap is created (Assignation operator)" << std::endl;
    return *this;
}

DiamondTrap::DiamondTrap( std::string name )
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
	std::cout << "💎: DiamondTrap is created (Parameterized constructor)" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "💎: DiamondTrap name is " << this->_name << "\n🤖: ClapTrap name is " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::attack( const std::string& target )
{
    ScavTrap::attack( target );
}

