/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:50:30 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/05 20:31:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Pardon", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm("Pardon", 25, 5)
{
	this->_target = src._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs )
{
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

void    PresidentialPardonForm::action( const Bureaucrat& executor ) const
{
    executor.getName();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void    PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	authentication( executor, *this );
	action( executor );
}