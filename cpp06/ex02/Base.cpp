/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:57:28 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/09 16:26:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"


Base::~Base( void )
{
}

Base	*generate( void )
{
	time_t t = time(NULL);
	srand((unsigned int)t);
	int	rnd = rand();
	if (rnd % 3 == 0)
	{
		Base *a = new A();
		return (a);
	}
	else if (rnd % 3 == 1)
	{
		Base *b = new B();
		return (b);
	}
	else if (rnd % 3 == 2)
	{
		Base *c = new C();
		return (c);
	}
	else
		return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Class A but with reference" << std::endl;
		(void) a;
	}
	catch (std::exception& e)
	{
		try 
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "Class B but with reference" << std::endl;
			(void) b;
		}
		catch (std::exception& e)
		{
			try 
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "Class C but with reference" << std::endl;
				(void) c;
			}
			catch (std::exception& e)
			{
				std::cout << "Unknown class" << std::endl;
			}
		}
	}
}
