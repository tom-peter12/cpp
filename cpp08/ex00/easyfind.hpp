/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:42:18 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/15 16:18:16 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <string>
# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <queue>
# include <algorithm>


template <class T>
size_t	easyfind(T &container, int integer)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), integer);
	if (it == container.end())
		throw std::exception();
	return std::distance(container.begin(), it);
}
