/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:53:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 14:10:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HORDE_HPP

# define ZOMBIE_HORDE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>


class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();

        void setName( std::string name );
        std::string getName( void ) const;
        
        void announce( void );
        
};


Zombie* zombieHorde( int N, std::string name );

# endif