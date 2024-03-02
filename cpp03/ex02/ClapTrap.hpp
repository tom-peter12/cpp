/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:40:24 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/27 21:27:26 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string	    _name;
        unsigned int    _hitPoints;
        unsigned int	_energyPoints;
        unsigned int	_attackDamage;
        
        unsigned int    _maxHitPoints;
        

    public:
        ClapTrap( void );
        virtual ~ClapTrap( void );
        ClapTrap( const ClapTrap& other );
        ClapTrap&	operator=( const ClapTrap& other );
        ClapTrap( std::string name );


        const std::string&	    getName( void ) const;
        unsigned int	        getHitPoints( void ) const;
        unsigned int	        getEnergyPoints( void ) const;
        unsigned int	        getAttackDamage( void ) const;
        
        void			        setName( std::string name );
        void			        setHitPoints( unsigned int hitPoints );
        void			        setEnergyPoints( unsigned int energyPoints );
        void			        setAttackDamage( unsigned int attackDamage );


        virtual void            attack( std::string const & target );
        void		            takeDamage( unsigned int amount );
        void		            beRepaired( unsigned int amount );
};


# endif