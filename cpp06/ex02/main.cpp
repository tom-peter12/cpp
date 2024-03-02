/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:02:05 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/09 16:53:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int	main( void )
{
	Base	*ptr = generate();
	identify(ptr);
	identify(*ptr);

	delete ptr;
}
