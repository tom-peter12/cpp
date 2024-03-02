/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:55:09 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 13:55:18 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
    Zombie zo;
    zo.setName("Zo");
    zo.announce();
    
    Zombie *newZ = newZombie("newZ");
    newZ->announce();
    
    randomChump("randomZ");
    
    delete newZ;
    return (0);
}

