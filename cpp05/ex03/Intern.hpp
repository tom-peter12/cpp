/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:24:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/30 23:42:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

		std::string _forms[3];
		
		AForm*		(Intern::*_makeForm[3])(std::string target);
		
	public:
		Intern( void );
		~Intern( void );
		Intern( const Intern& src );
		Intern& operator=( const Intern& rhs );


		AForm* makeForm( std::string formName, std::string target );
		AForm* makePresidentialPardonForm( std::string target );
		AForm* makeRobotomyRequestForm( std::string target );
		AForm* makeShrubberyCreationForm( std::string target );

		class UnkownFormGiven : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};

};


#endif