/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:44:07 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/25 16:29:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int		i;
		char	c;
		std::string holder;
		
		i = 1;
		while (i < argc)
		{
			holder = argv[i];
			for (std::string::iterator it = holder.begin(); it != holder.end(); ++it)
			{
				c = std::toupper(*it);
				std::cout << c;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
