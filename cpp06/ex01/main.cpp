/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:43:43 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/09 16:55:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data();
	data->id_num = 42;
	data->intra_login = "tpetros";
	data->full_name = "Tomas Petros Issac";

	uintptr_t ser = Serializer::serialize(data);
	std::cout << "Serialized  : " << ser << std::endl;

	std::cout << std::endl;

	Data *d = Serializer::deserialize(ser);
	std::cout << "Deserialized: " << d->id_num << std::endl;
	std::cout << "            : " << d->intra_login << std::endl;
	std::cout << "            : " << d->full_name << std::endl;

	delete data;
}

