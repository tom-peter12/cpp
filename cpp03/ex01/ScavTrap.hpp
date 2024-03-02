/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:39:36 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 20:25:14 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef SCAV_TRAP

# define SCAV_TRAP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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


# endif