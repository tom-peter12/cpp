/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:53:38 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/04 21:04:27 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>

template <typename T>
void display(T const& t)
{
	std::cout << t << std::endl;
}



template<typename T>
void	iter(T *arr, int len, void(*f)(T const&))
{
	int	i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}