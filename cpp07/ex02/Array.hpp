/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:16:11 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/10 19:12:40 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

template<typename T>
class Array
{
	private:
		T		*array;
		size_t	_size;

	public:
		Array( void ) : _size(0) { array = new T[_size]; }
		
		~Array( void ) { delete[] array; }

		Array( size_t n ) : array(new T[n]), _size(n) {  }
		
		Array( const Array& src )
		{
			this->array = NULL;
			*this = src;	
		}

		Array<T>& operator=( const Array& rhs )
		{
			if (this->array)
				delete[] array;
			if ( this != &rhs )
			{
				this->_size = rhs._size;
				this->array = new T[rhs._size];
				for (size_t i = 0; i < rhs._size; i++)
					this->array[i] = rhs[i];
			}
			return *this;
		}
		
		T&		  operator[]( size_t index ) const
		{
			if ((ssize_t)index < 0 || index > this->_size - 1)
				throw IndexOutOfBoundException();
			return array[index];
		}

		size_t size() const { return (this->_size); }
		
		class IndexOutOfBoundException : public std::exception
		{
			public: 
				virtual const char *what() const throw()
				{
					return "IndexOutOfBoundException";
				}
		};
};


template <typename T>
std::ostream& operator<<( std::ostream& COUT, const Array<T>& array ) {
    COUT << "[";
    for ( size_t i = 0 ; i < array.size(); i++ ) {
        COUT << array[i];
        if (i < array.size() - 1)
            COUT << ", ";
    }
    COUT << "]";
    return COUT;
}
