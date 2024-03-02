/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:54:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/23 16:17:01 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal( void );
        WrongAnimal( const WrongAnimal &other );
        WrongAnimal&  operator=( const WrongAnimal &other );
        virtual ~WrongAnimal( void );

        void                setType( std::string type );
        std::string const   &getType( void ) const;
        void        makeSound( void ) const;
};


# endif