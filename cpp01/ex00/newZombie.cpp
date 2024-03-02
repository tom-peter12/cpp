/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:55:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 13:52:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/**
 * @brief Creates a new dynamically allocated Zombie object.
 * 
 * This function acts as a factory method to create a new Zombie instance
 * on the heap. It allows for the encapsulation of the object creation
 * and initialization process.
 *
 * @param name The name to be assigned to the new Zombie object.
 * @return Zombie* A pointer to the newly created Zombie object.
 * 
 * @note The caller is responsible for deleting the returned object to 
 *       avoid memory leaks.
 */


Zombie* newZombie( std::string name )
{
    Zombie *newZ = new Zombie();
	newZ->setName( name );
    return ( newZ );
}

