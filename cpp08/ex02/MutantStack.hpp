/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:53:15 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/12 15:20:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <stack>
# include <exception>
# include <string>
#include <algorithm>
#include <deque>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void);
		~MutantStack( void );
		MutantStack(MutantStack const &other);
		MutantStack &operator=(MutantStack const &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin( void );
		iterator end( void );

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin( void ) const;
		const_iterator end() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin( void );
		reverse_iterator rend( void );

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

};


# include "MutuantStack.tpp"