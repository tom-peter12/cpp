/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:36:22 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/28 00:36:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef CAT_HPP

# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <sstream>

class Cat : public AAnimal
{
    private:
        Brain *_brain;
        
    public:
        Cat( void );
        Cat( const Cat &other );
        Cat&  operator=( const Cat &other );
        ~Cat( void );

        void    makeSound( void ) const;

        Brain*  getBrain( void ) const;
};



# endif


