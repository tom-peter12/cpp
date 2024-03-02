/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:29:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/26 21:30:26 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string     _type;
    
    public:
        Animal( void );
        Animal( const Animal &other );
        Animal&  operator=( const Animal &other );
        virtual ~Animal( void );

    
    void                setType( std::string type );
    std::string const   &getType( void ) const;

    virtual void        makeSound( void ) const;
};



# endif