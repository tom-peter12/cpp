/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/26 16:58:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( void );
        ~FragTrap( void );
        FragTrap( const FragTrap &other );
        FragTrap &	operator=( FragTrap const & other );
        
        FragTrap( std::string name );

        void highFivesGuys(void); 
        void    attack( std::string const & target );
};

# endif