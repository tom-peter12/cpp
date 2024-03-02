/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:37:52 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/21 14:50:23 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}


/* Setters */
// ---------------------------------------------------------------- //
void	Contact::set_f_name(std::string f_name) { this->f_name = f_name; }

void	Contact::set_l_name(std::string l_name) { this->l_name = l_name; }

void	Contact::set_n_name(std::string n_name) { this->n_name = n_name; }

void	Contact::set_p_number(std::string p_number) { this->p_number = p_number; }

void	Contact::set_d_secret(std::string d_secret) { this->d_secret = d_secret; }

// ---------------------------------------------------------------- //

/* Getters*/
// ================================================================= //

std::string	Contact::get_f_name(void) const { return this->f_name; }

std::string	Contact::get_l_name(void) const { return (this->l_name); }

std::string	Contact::get_n_name(void) const { return (this->n_name); }

std::string	Contact::get_p_number(void) const { return  (this->p_number); }

std::string Contact::get_d_secret(void) const { return (this->d_secret); }

// ================================================================= //