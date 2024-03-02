/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:36:25 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/22 16:47:37 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <sstream>
# include <sys/time.h>
# include <stdint.h>
# include <climits>
# include <algorithm>

# include <vector>
# include <list>

typedef std::pair<long, long> PAIRS;
class PmergeMe 
{
	private:
		static std::vector<long> _vec;
		static std::vector<long> _rvec;

		static std::list<long> _lst;
		static std::list<long> _rlst;

		PmergeMe( void );
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe( void );

	public:

		static void parse(int ac, char **av);
		template <typename T>
		static void do_sorting(std::string msg, T (*sort)(void), T &sorted);


		static void binary_insert(long num);
		static void binary_insertion(std::vector<PAIRS> pairs);
		static std::vector<PAIRS> &make_pairsv(std::vector<PAIRS> &pairs);
		static std::vector<long> sort_vec();

		static void binary_insert_lst(long num);
		static void binary_insertion_lst(std::list<PAIRS> pairs);
		static std::list<PAIRS> &make_pairs_lst(std::list<PAIRS> &pairs);
		static std::list<long> sort_lst();
		
		static void compare();

		class InvalidCharacters : public std::exception 
		{
			public:
				const char *what() const throw();
		};

		class InvalidOutOfBoundNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};

};


template <typename T>
void print_seq(std::string msg, T &cont)
{
	int i = 0;

	std::cout << msg << "[ ";
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++, i++)
	{
		if (i >= 6)
		{
			std::cout << "... ";
			break;
		}
		std::cout << *it << " ";
	}
	std::cout << "] ";
}