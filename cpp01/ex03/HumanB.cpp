/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:51:37 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 15:16:37 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
# include "Weapon.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
}


HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " isn't equiped with a weapon" << std::endl;
}


void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

