/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:40:07 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 01:25:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "./harlFilter [DEBUG, INFO, WARNING, ERROR]" << std::endl;
        return (1);
    }

    Harl    harl;

    harl.complain(argv[1]);
    return (0);
}
