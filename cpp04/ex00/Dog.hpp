/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:45:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 23:14:47 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        Dog( const Dog &other );
        Dog&  operator=( const Dog &other );
        ~Dog( void );

        void    makeSound( void ) const;
};


# endif

