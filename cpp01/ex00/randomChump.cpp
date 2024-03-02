/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:55:00 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 13:41:20 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/**
 * @method void randomChump(std::string name);
 *
 * @brief Creates a new Zombie instance, sets its name, and immediately announces it.
 *
 * This method demonstrates a way to quickly create a named Zombie on the stack and make an announcement.
 * Note: Since the Zombie is created on the stack, it will be automatically destroyed when this method exits.
 *
 * @param name The name to assign to the newly created Zombie.
 */

void randomChump( std::string name )
{
    Zombie zo = Zombie();
    zo.setName( name );
    zo.announce();
}

