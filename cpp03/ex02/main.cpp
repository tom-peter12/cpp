/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 21:15:45 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	ClapTrap	Eve("Eve");
	ScavTrap	Bob("Bob");
	FragTrap	Alice("Alice");

	std::cout << std::endl;
	Alice.attack("Bob");
	Bob.takeDamage(10);
	Bob.beRepaired(2);
	Eve.attack("Alice");
	Alice.takeDamage(50);
	Alice.beRepaired(2);
	Eve.beRepaired(20);
	Alice.highFivesGuys();
	Bob.guardGate();
	std::cout << std::endl;
	
	return (0);
}