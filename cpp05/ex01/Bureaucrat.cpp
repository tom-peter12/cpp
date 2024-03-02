/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:54:55 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/08 14:15:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade > 150)
		throw ( Bureaucrat::GradeTooLowException() );
	else if (grade <= 0)
		throw ( Bureaucrat::GradeTooHighException() );
	else
		this->_grade = grade;	
}

std::ostream& operator<<( std::ostream& COUT, const Bureaucrat& bureau )
{
	COUT << "👨‍💼: " << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return (COUT);
}


// Getters and Setters

const std::string&	Bureaucrat::getName( void ) const { return this->_name; }

int					Bureaucrat::getGrade( void ) const { return this->_grade; }


void	Bureaucrat::incrementGrade( int incr_value )
{
	if ( incr_value < 0 )
		throw (Bureaucrat::IncrementValueTooLow());
	this->_grade -= incr_value;
	if (this->_grade <= 0)
		throw ( Bureaucrat::GradeTooHighException() );
}

void	Bureaucrat::decrementGrade( int decr_value )
{
	this->_grade += decr_value;
	if (this->_grade > 150)
		throw ( Bureaucrat::GradeTooLowException() );
}

const char* Bureaucrat::IncrementValueTooLow::what() const throw()
{
	return "Bureaucrat::IncrementValueTooLow";
}

void Bureaucrat::signForm( Form& form )
{
	if (form.getSign() == true)
		throw (Form::FormAlreadySigned());
	if (this->getGrade() <= form.get_g_t_sign())
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	else
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << GradeTooLowException().what() << std::endl;
		throw (Form::GradeTooLowException());
	}
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}
