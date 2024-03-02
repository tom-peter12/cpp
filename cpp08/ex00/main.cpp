/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:42:51 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/11 16:05:14 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main(void)
{
	
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		std::cout << "\x1b[31mTESTING VECTOR\x1b[0m" << std::endl;
		std::cout << std::string(40, '-') << std::endl;
		try
		{
			std::cout << easyfind(vec, 4) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::string(40, '-') << std::endl << std::endl;
	}


	{
		std::deque<int> deq;
		deq.push_back(1);
		deq.push_back(2);
		deq.push_back(3);
		std::cout << "\x1b[32mTESTING DEQUE\x1b[0m" << std::endl;
		std::cout << std::string(40, '*') << std::endl;
		try
		{
			std::cout << easyfind(deq, 3) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::string(40, '*') << std::endl << std::endl;
	}
	


	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		std::cout << "\x1b[33mTESTING LIST\x1b[0m" << std::endl;
		std::cout << std::string(40, '=') << std::endl;
		try
		{
			std::cout << easyfind(lst, 3) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::string(40, '=') << std::endl << std::endl;
	}
	
	
	
	// {
	// 	std::queue<int> que;
	// 	que.push(1);
	// 	que.push(2);
	// 	que.push(3);
	// 	std::cout << "TESTING QUEUE/STACK" << std::endl;
	// 	std::cout << std::string(40, '#') << std::endl;
	// 	try
	// 	{
	// 		std::cout << easyfind(que, 3) << std::endl;
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << "Exception: " << e.what() << std::endl;
	// 	}
	// 	std::cout << std::string(40, '#') << std::endl << std::endl;
	// }
	
	return 0;
}