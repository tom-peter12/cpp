/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/01 14:16:49 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
	ScavTrap Alice("Alice");
	ClapTrap Bob("Bob");
	ScavTrap Redat;
	Redat = Alice;

	std::cout << std::endl;
	Alice.attack("Bob");
	Bob.takeDamage(0);
	Bob.takeDamage(2);
	Bob.beRepaired(2);
	Bob.takeDamage(10);
	Alice.takeDamage(50);
	Alice.beRepaired(INT_MAX);
	Redat.attack("Alice");
	Redat.guardGate();
	std::cout << std::endl;
	return 0;
}
