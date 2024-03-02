/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:17:15 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/09 15:11:47 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# pragma once

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	int			id_num;
	std::string	intra_login;
	std::string	full_name;
};

class Serializer
{
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer( void );
		~Serializer( void );
		Serializer( const Serializer& src );
		Serializer& operator=( const Serializer& rhs );
};

# endif
