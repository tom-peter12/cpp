/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:33:42 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/15 16:48:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span( void )
{
}

Span::~Span( void )
{
}

Span::Span( size_t N ) : _size(N), _nums()
{
}

Span::Span( const Span& src )
{
	*this = src;
}

Span& Span::operator=( const Span& rhs )
{
	if (this != &rhs)
	{
		this->_nums.clear();
		this->_size = rhs._size;
		this->_nums = rhs._nums;
	}
	return (*this);
}

void	Span::addNumber( int num )
{
	if (_nums.size() > this->_size - 1)
		throw Span::InsertionAtOutOfBound();
	this->_nums.push_back(num);
}

size_t	Span::longestSpan( void )
{
	if (this->_nums.empty() || this->_nums.size() == 1)
		throw Span::EmptyOrLessElementsToSpan();

	std::vector<int>::iterator maxElement = std::max_element(this->_nums.begin(), this->_nums.end());
	std::vector<int>::iterator minElement = std::min_element(this->_nums.begin(), this->_nums.end());

	return (*maxElement - *minElement);

}

size_t Span::shortestSpan( void )
{
	if (this->_nums.empty() || this->_nums.size() == 1)
		throw EmptyOrLessElementsToSpan();

	std::sort(this->_nums.begin(), this->_nums.end());
	
	size_t shortest = std::numeric_limits<size_t>::max();
	size_t diff;
	
	std::vector<int>::iterator it;
	
	for (it = _nums.begin(); it != _nums.end(); ++it)
	{
		diff = std::abs(*it - *(it + 1));
		if (diff < shortest)
			shortest = diff;
	}

	return shortest;
}

void Span::fillSpan(std::vector<int>::iterator& begin, std::vector<int>::iterator& end)
{
	if (_nums.size() + std::distance(begin, end) > _size)
		throw SpanFullException();
	while (begin != end)
		_nums.push_back(*begin++);
}

const std::vector<int>& Span::getNums( void ) const { return this->_nums; }

const char *Span::InsertionAtOutOfBound::what() const throw()
{
	return "Span::InsertionAtOutOfBound";
}

const char *Span::EmptyOrLessElementsToSpan::what() const throw()
{
	return "Span::EmptyOrLessElementsToSpan";
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span::SpanFullException";
}
std::ostream& operator<<(std::ostream& COUT, const Span& sp)
{
	COUT << "[";
	for (std::vector<int>::const_iterator it = sp.getNums().begin(); it != sp.getNums().end(); ++it)
	{
		COUT << *it;
		if ((it + 1) != sp.getNums().end())
			COUT << ", ";
	}
	COUT << "]" << std::endl;
	return COUT;
}