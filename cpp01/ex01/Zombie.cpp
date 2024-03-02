/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:53:07 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 14:01:21 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << "\t:\t is dead" << std::endl;
}

std::string Zombie::getName(void) const { return (this->_name); }

void Zombie::setName(std::string name)
{
	if (name.empty())
		name = "defaultZ";
	this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << this->_name << "\t:\t BraiiiiiiinnnzzzZ..." << std::endl;
}
