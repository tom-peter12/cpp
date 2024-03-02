/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:45:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/28 00:37:46 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef DOG_HPP

# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain   *_brain;
        
    public:
        Dog( void );
        Dog( const Dog &other );
        Dog&  operator=( const Dog &other );
        ~Dog( void );

        void    makeSound( void ) const;

        Brain*  getBrain( void ) const;
};


# endif

