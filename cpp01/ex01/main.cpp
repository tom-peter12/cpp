/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:53:12 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 15:18:03 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
	int N = 4;
	
	// std::cout << "Create your zombie horde: ";
	// std::cin >> N;
	// if (std::cin.eof())
	// {
	// 	std::cout << std::endl;
	// 	std::cin.clear();
	// 	std::exit(1);
	// }

	// if (std::cin.fail() || (N < 1))
	// {
	// 	std::cout << "Please enter a valid input" << std::endl;
	// 	std::exit(1);
	// }
	
    Zombie *horde = zombieHorde( N, "Alice" );
    
    for ( int i = 0; i < N; i++ )
        horde[i].announce();

    delete[] horde;
    
    return ( 0 );
}

