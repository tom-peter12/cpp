/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:03:05 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/15 16:43:43 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

void	test_subject( void )
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	test()
{
	{
		Span sp_full = Span(2);
		sp_full.addNumber(5);
		sp_full.addNumber(8);

		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp_full << std::endl;
		std::cout << "[+] ADD when is full [+]"  << std::endl;
		try
		{
			sp_full.addNumber(9);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " << e.what() <<  std::endl << std::endl << std::endl;
		}
	}


	
	{
		Span sp_short = Span(5);
		sp_short.addNumber(5);
		sp_short.addNumber(90);
		sp_short.addNumber(17);
		sp_short.addNumber(-8925);
		sp_short.addNumber(11);
		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp_short << std::endl;
		std::cout << "[+] Shortest diference [+]"  << std::endl;
		std::cout << sp_short.shortestSpan() << std::endl << std::endl << std::endl;
	}



	{
		Span sp_empty = Span(80);
		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp_empty << std::endl;
		std::cout << "[+] Empty exception 0 numbers[+]"  << std::endl;
		try
		{
			std::cout << sp_empty.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " << e.what() <<  std::endl;
		}

		sp_empty.addNumber(5);
		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp_empty << std::endl;
		std::cout << "[+] Empty exception with one Number [+]"  << std::endl;
		try
		{
			std::cout << sp_empty.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " << e.what() <<  std::endl << std::endl << std::endl;
		}
	}

    {
		Span sp_long = Span(4);
		sp_long.addNumber(8);
		sp_long.addNumber(-3);
		sp_long.addNumber(80);
		sp_long.addNumber(-8);
		std::cout << "[+] The Contents of the Span [+]" << std::endl;
		std::cout << sp_long << std::endl;
		std::cout << "[+] Long Span [+]"  << std::endl;
		try
		{
		    std::cout << sp_long.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
		    std::cerr << "Error : " << e.what() <<  std::endl << std::endl << std::endl;
   		}
	}



	{
		std::cout << "[+] Auto Filling the Span [+]"  << std::endl;

		try
		{
			Span sp_auto = Span(1000000);
			std::vector<int> range(1000000);
			std::srand(time(NULL));
			std::generate(range.begin(), range.end(), std::rand);
			std::vector<int>::iterator begin = range.begin();
			std::vector<int>::iterator end = range.end();
			sp_auto.fillSpan(begin, end);
			// std::cout << "[+] The Contents of the Span [+]" << std::endl;
			// std::cout << sp_auto << std::endl;
			std::cout << sp_auto.longestSpan() << std::endl;
			std::cout << sp_auto.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " << e.what() <<  std::endl;
		}
	}

}

int main()
{
	test_subject();
	std::cout << std::string(50, '-') << std::endl;
	test();
	return (0);
}