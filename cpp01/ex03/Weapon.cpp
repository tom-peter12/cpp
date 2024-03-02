/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:50:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 15:20:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon( std::string type ) 
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

void Weapon::setType( std::string const type) { this->_type = type; }

std::string const &Weapon::getType(void) const { return this->_type; }


