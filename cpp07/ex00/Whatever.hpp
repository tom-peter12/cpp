/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:37:22 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/14 20:55:04 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
// # include <string>

template<typename T>
T min(T& one, T& two)
{
	return (one < two ? one : two);
}

template<class T>
T max(T& one, T& two)
{
	return (one > two ? one : two);
}

template<typename T>
void swap(T& one, T& two)
{
	T tmp;
	tmp = two;
	two = one;
	one = tmp;
}

#endif
