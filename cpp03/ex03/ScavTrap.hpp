/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:39:36 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/26 19:39:19 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
    
    public:
        ScavTrap( void );
        ~ScavTrap( void );
        ScavTrap( ScavTrap const & other );
        ScavTrap &operator=(ScavTrap const & other);
        ScavTrap( std::string name );

        void attack( const std::string& target );
        void guardGate( void );
};

#  endif
