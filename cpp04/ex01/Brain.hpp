/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:39:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/02 15:04:17 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# ifndef BRAIN_HPP

# define BRAIN_HPP

# include <iostream>
# include <string>
# include <sstream>

class Brain
{
    private:
        std::string _ideas[100];
    
    public:
        Brain( void );
        ~Brain( void );
        Brain( const Brain &other );
        Brain&  operator=( const Brain &other );

        void                    setIdea( std::string idea, unsigned int index );
        const std::string&      getIdea( unsigned int index ) const;
        
        static std::string    conv(int value);
};


# endif
