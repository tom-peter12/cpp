/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/26 19:38:12 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap( void );
        virtual ~FragTrap( void );
        FragTrap( std::string name );
        FragTrap( const FragTrap &other );
        
        FragTrap &	operator=( FragTrap const & other );

        void highFivesGuys(void); 
        void    attack( std::string const & target );
};

# endif
