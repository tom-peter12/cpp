/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/01 14:47:49 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond;
	
	diamond.attack("Somebody");
	diamond.beRepaired(5);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();

	return 0;
}