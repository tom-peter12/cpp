/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:55:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 13:41:42 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>


/**
 * @class Zombie
 * 
 * @brief Represents a simple object with a name.
 *
 * The Zombie class provides basic functionalities to create and announce a Zombie instance.
 * 
 * @member _name Holds the name of the Zombie.
 * 
 * @method Zombie(void) Default constructor that initializes a new instance of the Zombie class.
 * 
 * @method ~Zombie(void) Destructor that destroys the Zombie instance and cleans up any allocated resources.
 * 
 * @method announce(void) Announces the name of the Zombie to the console or any other output medium.
 * 
 * @method newZombie(std::string name) 
 * Creates a new Zombie with the specified name and returns a pointer to it.
 * @param name The name of the new Zombie.
 * @return A pointer to a dynamically allocated Zombie instance.
 * 
 * @method randomChump(std::string name) 
 * Creates and announces a Zombie with the given name.
 * @param name The name of the Zombie.
 * 
 * @method std::string getName(void) 
 * Accessor method that returns the name of the Zombie.
 * @return The name of the Zombie.
 * 
 * @method void setName(std::string name) 
 * Mutator method that sets the name of the Zombie.
 * @param name The new name for the Zombie.
 * 
 */



class Zombie 
{
    private:
        std::string _name;
    
    public:
        Zombie( void );
        ~Zombie( void );
        
        void announce( void );
        
        std::string getName( void ) const;
        void setName( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

# endif

