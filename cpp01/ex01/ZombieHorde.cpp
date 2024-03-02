/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:53:01 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 14:44:21 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zoHorde = new Zombie[N];
    for ( int i = 0; i < N; i++ )
        zoHorde[i].setName( name );
    return ( zoHorde );
}

