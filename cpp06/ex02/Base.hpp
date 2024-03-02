/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:57:31 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/09 16:53:44 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <stdint.h>
# include <iostream>
# include <string>
# include <exception>
# include <time.h>
# include <stdlib.h>

class Base
{
	public:
		virtual ~Base( void );
};

Base	*generate( void );
void	identify(Base* p);
void	identify(Base& p);

