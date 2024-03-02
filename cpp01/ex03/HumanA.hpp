/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:50:46 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 15:46:57 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMAN_A_HPP

# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string 	_name;
		Weapon 			&_weapon;
		
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA(void);
		void	attack(void);
};

# endif

