/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:47:31 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/05 16:55:37 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP

# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
    private:
        void        debug( void );
        void        info( void );
        void        warning( void );
        void        error( void );

    public:
        Harl( void );
        ~Harl( void );

        void        complain( std::string level );
};



# endif