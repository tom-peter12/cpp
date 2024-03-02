/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:29:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 16:41:44 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
    protected:
        std::string     _type;
    
    public:
        AAnimal( void );
        AAnimal( const AAnimal &other );
        AAnimal&  operator=( const AAnimal &other );
        virtual ~AAnimal( void );

    
    void                setType( std::string type );
    std::string const   &getType( void ) const;

    virtual void        makeSound( void ) const = 0;
};



# endif