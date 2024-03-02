/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:36:55 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/21 14:44:48 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string p_number;
		std::string d_secret;

	public:
		Contact();
		~Contact();

		// Getters and Setter Functions
		void	set_f_name(std::string f_name);
		void	set_l_name(std::string l_name);
		void	set_n_name(std::string n_name);
		void	set_p_number(std::string p_number);
		void	set_d_secret(std::string d_secret);

		std::string	get_f_name(void) const;
		std::string	get_l_name(void) const;
		std::string	get_n_name(void) const;
		std::string	get_p_number(void) const;
		std::string	get_d_secret(void) const;
		
};

#endif
