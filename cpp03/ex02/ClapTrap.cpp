/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:41:54 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 21:28:36 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name( "Claptrappington" ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ), _maxHitPoints( _hitPoints )
{
	std::cout << "🤖: ClapTrap is created (Default constructor)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "🤖 -> 💀: ClapTrap is destroyed (Default destructor)" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other )
{
	*this = other;
	std::cout << "🤖: ClapTrap is created (Copy constructor)" << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const & other )
{
	if ( this != &other )
	{
		this->setName( other.getName() );
		this->setHitPoints( other.getHitPoints() );
		this->setEnergyPoints( other.getEnergyPoints() );
		this->setAttackDamage( other.getAttackDamage() );
		std::cout << "🤖: ClapTrap is created (Copy assignment operator)" << std::endl;
	}
	return (*this);
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ), _maxHitPoints( _hitPoints )
{
	std::cout << "🤖: ClapTrap is created (Parameterized constructor)" << std::endl;
}


const std::string	    &ClapTrap::getName( void ) const { return (this->_name); }
unsigned int			ClapTrap::getHitPoints( void ) const { return (this->_hitPoints); }
unsigned int			ClapTrap::getEnergyPoints( void ) const { return (this->_energyPoints); }
unsigned int			ClapTrap::getAttackDamage( void ) const { return (this->_attackDamage); }
void            		ClapTrap::setName( std::string name ) { this->_name = name; }
void            		ClapTrap::setHitPoints( unsigned int hitPoints ) { this->_hitPoints = hitPoints; }
void            		ClapTrap::setEnergyPoints( unsigned int energyPoints ) { this->_energyPoints = energyPoints; }
void            		ClapTrap::setAttackDamage( unsigned int attackDamage ) { this->_attackDamage = attackDamage; }



void	ClapTrap::attack( const std::string &target )
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has no energy points left." << std::endl;
	else
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" is not able to attack " << target << ", because it has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( this->_hitPoints >= amount && this->_hitPoints > 0 )
		this->_hitPoints -= amount;
	else if ( this->_hitPoints < amount && this->_hitPoints > 0 )
		this->_hitPoints = 0;
	else
	{
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" is already dead, stop beating it." << std::endl;
		return ;
	}
	std::cout << "🤖: ClapTrap : \"" << this->_name << "\" was attacked and lost " << amount << " hit points, it now has " << this->_hitPoints << " hit points." << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= _maxHitPoints )
	{
		this->_hitPoints += amount;
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" repaired itself and gained " << amount << " of hit points, it now has " << this->_hitPoints << " hit points." << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" is not able to repair itself, because it doesn't have enough energy points." << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" is not able to repair itself, because it doesn't have enough hit points." << std::endl;
	else
		std::cout << "🤖: ClapTrap : \"" << this->_name << "\" can't be repaired to have more than 10 hit points." << std::endl;
}

