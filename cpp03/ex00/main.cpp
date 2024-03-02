/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:39:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/30 16:28:06 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << "🤖: Test on stack" << std::endl << std::endl;
        ClapTrap    alice("Alice");
        alice.attack("Bob");
        alice.takeDamage(5);
        alice.beRepaired(5);
        alice.takeDamage(1);
        alice.beRepaired(1);
        alice.takeDamage(1);
    }
    std::cout << "🤖: Test ended" << std::endl << std::endl;

    {
        std::cout << "🤖: Test on heap" << std::endl << std::endl;
        ClapTrap    *alice = new ClapTrap("Alice");
        alice->attack("Bob");
        alice->takeDamage(5);
        alice->beRepaired(5);
        alice->takeDamage(15);
        alice->beRepaired(15);
        alice->takeDamage(100);
        delete alice;
        
        std::cout << "🤖: Test ended" << std::endl << std::endl;
    }
    
    return (0);
}
