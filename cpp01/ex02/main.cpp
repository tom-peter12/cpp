/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:47:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/05 17:16:23 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");

	std::string		*stringPTR = &str;
	std::string		&stringREF = str;
	
	
	std::cout << "The memory address of the string variable  : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR       : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF       : " << &stringREF << std::endl;
	
	
	std::cout << "The value of the string variable           : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR          : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF          : " << stringREF << std::endl;
}
