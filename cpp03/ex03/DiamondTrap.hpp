/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:51:08 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/01 14:46:14 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap( void );
        ~DiamondTrap( void );
        DiamondTrap( DiamondTrap const & other );
        DiamondTrap    &operator=( DiamondTrap const &other );
        
        DiamondTrap( std::string name );
        
        void attack( const std::string& target );
        void    whoAmI( void );
};



# endif