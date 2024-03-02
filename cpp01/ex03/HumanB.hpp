/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:51:42 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 01:07:37 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMAN_B_HPP

# define HUMAN_B_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string 	_name;
		Weapon 			*_weapon;
		
	public:

		HumanB( std::string name );
		~HumanB(void);
		void	attack(void);

		void		setWeapon( Weapon &weapon );
};


# endif

