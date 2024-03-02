/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:27:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/19 15:57:44 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstring>
# include <iostream>
# include <fstream>

std::string replace(std::string str, const std::string &old, const std::string &neW) 
{
    size_t pos = str.find(old);
    while (pos != std::string::npos) 
	{
        str.erase(pos, old.length());
        str.insert(pos, neW);
        pos = str.find(old, pos + neW.length());
    }
    return str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}
	
	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	
	if ( file.empty() || s1.empty() || s2.empty() )
	{
		std::cout << "Error: Non of the arguments should be empty" << std::endl;
		return 1;
	}

	std::ifstream infile;
	std::ofstream outfile;
	
	infile.open(file.c_str());
	if ( !infile.is_open() )
	{
		std::cout << "Error: InFile failed to be opened." << std::endl;
		return (1);
	}
	outfile.open((file + std::string(".replace")).c_str());
	if ( !outfile.is_open() )
	{
		std::cout << "Error: OutFile failed to be opened." << std::endl;
		infile.close();
		return (1);
	}
	
	std::string tmp;
	char 		c;

	while (infile.good())
	{
		while (infile.get(c) && c != '\n' && c != ' ')
			tmp += c;
		if (std::strstr(tmp.c_str(), s1.c_str()))
		{
			std::string holder = replace(tmp, s1, s2);
			outfile << holder;
		}
		else
			outfile << tmp;
		if (infile.good() && (c == '\n' || c == ' '))
			outfile << c;
		tmp.clear();
	}
	
	infile.close();
	outfile.close();
}
