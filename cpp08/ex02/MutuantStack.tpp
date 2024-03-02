/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutuantStack.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:35:32 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/12 14:57:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
MutantStack<T>::MutantStack( void )
{
	std::stack<T>::c = std::deque<T>();
}

template <typename T>
MutantStack<T>::~MutantStack( void )
{
}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const &src ) : std::stack<T>( src )
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( MutantStack<T> const &rhs )
{
	if ( this != &rhs )
		this->c = rhs.c;
	return (*this);
}


// Normal Iterators -> These iterators are read and write.
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
	return (std::stack<T>::c.begin());
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
	return (std::stack<T>::c.end());
}


// Const Iterators -> These iterators are read only.
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const
{
	return (std::stack<T>::c.begin());
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const
{
	return (std::stack<T>::c.end());
}



// Reverse Iterators -> These iterators travers in reverse (end -> begin)
// (rbegin -> end && rend ->begin)
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin( void )
{
	return (std::stack<T>::c.rbegin());
}
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend( void )
{
	return (std::stack<T>::c.rend());
}


// Const Reverse Iterators -> This are similar to Const Iterators and Reverse Iterators
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin( void ) const
{
	return (std::stack<T>::c.rbegin());
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend( void ) const
{
	return (std::stack<T>::c.rend());
}

