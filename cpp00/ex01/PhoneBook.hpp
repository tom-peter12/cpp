/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:36:46 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/25 17:12:51 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONE_BOOK_HPP

# define PHONE_BOOK_HPP

# include <iostream>
# include <string>
# include <cstddef>
# include <iomanip>
# include <cstdlib>
# include <sstream>
# include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8];
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(size_t *index);
		void	search();
		
		int				validate_str(std::string inp);
		int				validate_phone(std::string inp);
		int				print_all(void);
		void			print_contact(int num);
		void			print_intro(void);
		void			print_outro(void);
		int				input_value(void);
		std::string		accept_inp(std::string message);
};

# endif
