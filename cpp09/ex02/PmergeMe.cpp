/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:36:16 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/22 17:06:08 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<long> PmergeMe::_vec;
std::vector<long> PmergeMe::_rvec;

std::list<long> PmergeMe::_lst;
std::list<long> PmergeMe::_rlst;

const char *PmergeMe::InvalidCharacters::what() const throw()
{
	return ("PmergeMe:InvalidCharacters");
}

const char *PmergeMe::InvalidOutOfBoundNumber::what() const throw()
{
	return ("PmergeMe:InvalidOutOfBoundNumber");
}

std::string trim(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (isspace(*it) || *it == '\t'))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && (isspace(*rit) || *rit == '\t'))
        rit++;

    return std::string(it, rit.base());
}

bool	is_only(std::string s, std::string chars)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (chars.find(s[i]) == std::string::npos)
			return (false);
	}
	return (true);
}

void PmergeMe::parse(int ac, char **av)
{
	std::string s_num;
	long num;
	for (int i = 1; i < ac; i++)
	{
		s_num = av[i];
		if (!is_only(s_num, "0123456789") || s_num.empty())
			throw PmergeMe::InvalidCharacters();
		
		std::istringstream ss(s_num);
		ss >> num;

		if (num > INT_MAX)
			throw PmergeMe::InvalidOutOfBoundNumber();
		if (std::find(_vec.begin(), _vec.end(), num) == _vec.end())
			_vec.push_back(num);
		if (std::find(_lst.begin(), _lst.end(), num) == _lst.end())
			_lst.push_back(num);
	}
}

time_t	get_timestamp(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1e6 + now.tv_usec);
}

void print_time(long start, long end, std::string msg = "")
{
	double duration = double(end - start);

	std::cout << msg <<
		((duration > 10000) ? duration / 1000 : duration) <<
		((duration > 10000) ? "ms" : "µs") <<
		std::endl;
}

template <typename T>
void PmergeMe::do_sorting(std::string msg, T (*sort)(void), T &sorted)
{
	time_t start = get_timestamp();
	sorted = sort();
	time_t end = get_timestamp();

	print_seq(msg, sorted);
	print_time(start, end, "=> ");
}

void PmergeMe::compare()
{
	std::cout << std::endl;
	print_seq("Before: ", _vec);

	std::cout << std::endl;
	do_sorting("Sorting std::vec: ", &sort_vec, _rvec);
	do_sorting("Sorting std::list: ", &sort_lst, _rlst);
	std::cout << std::endl;
}

void pair_insert(std::vector<PAIRS> &pairs, std::pair<long, long> &p)
{
	for (std::vector<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > p.first)
		{
			pairs.insert(it, p);
			return ;
		}
	}
	pairs.push_back(p);
}

std::vector<PAIRS> &PmergeMe::make_pairsv(std::vector<PAIRS> &pairs)
{
	long a;
	PAIRS p;

	for (std::vector<long>::iterator it = _vec.begin(); it != _vec.end(); ++it)
	{
		a = *it++;
		if (it == _vec.end())
		{
			_rvec.push_back(a);
			break;
		}
		long b = *it;
		p = (a < b) ? PAIRS(a, b) : PAIRS(b, a);
		pair_insert(pairs, p);
	}
	return (pairs);
}

void PmergeMe::binary_insert(long num)
{
	int low = 0;
	int high = _rvec.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (num <= _rvec[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	std::vector<long>::iterator place = _rvec.begin() + low;
	_rvec.insert(place, num);
}

void PmergeMe::binary_insertion(std::vector<PAIRS> pairs)
{
	long last = -1;

	if (_rvec.size() == 1)
	{
		last = _rvec.back();
		_rvec.pop_back();
	}
	for (std::vector<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		_rvec.push_back(it->first);
	for (std::vector<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		binary_insert(it->second);
	if (last != -1)
		binary_insert(last);
}

std::vector<long> PmergeMe::sort_vec()
{
	std::vector<PAIRS> pairs;
	pairs = make_pairsv(pairs);
	binary_insertion(pairs);
	return (_rvec);
}





void PmergeMe::binary_insert_lst(long num)
{
	if (_rlst.empty())
	{
		_rlst.push_back(num);
		return;
	}

	std::list<long>::iterator low = _rlst.begin();
	std::list<long>::iterator high = _rlst.end();
	--high;

	while (low != high)
	{
		std::list<long>::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);

		if (*mid >= num)
			high = mid;
		else
		{
			low = mid;
			++low;
		}
	}
	if (*low < num && low != _rlst.end())
		++low;
	_rlst.insert(low, num);
}


void PmergeMe::binary_insertion_lst(std::list<PAIRS> pairs)
{
	long last = -1;

	if (_rlst.size() == 1)
	{
		last = _rlst.back();
		_rlst.pop_back();
	}
	for (std::list<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		_rlst.push_back(it->first);
	for (std::list<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		binary_insert_lst(it->second);
	if (last != -1)
		binary_insert_lst(last);
}

void pair_insert_lst(std::list<PAIRS> &pairs, std::pair<long, long> &p)
{
	for (std::list<PAIRS>::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > p.first)
		{
			pairs.insert(it, p);
			return ;
		}
	}
	pairs.push_back(p);
}

std::list<PAIRS>& PmergeMe::make_pairs_lst(std::list<PAIRS>& pairs)
{
	long a;
	PAIRS p;

	for (std::list<long>::iterator it = _lst.begin(); it != _lst.end(); ++it)
	{
		a = *it++;
		if (it == _lst.end())
		{
			_rlst.push_back(a);
			break;
		}
		long b = *it;
		p = (a < b) ? PAIRS(a, b) : PAIRS(b, a);
		pair_insert_lst(pairs, p);
	}
	return pairs;
}

std::list<long> PmergeMe::sort_lst()
{
	std::list<PAIRS> pairs;
	pairs = make_pairs_lst(pairs);
	binary_insertion_lst(pairs);
	return (_rlst);
}