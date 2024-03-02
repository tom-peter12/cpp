/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:26:43 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/04 14:17:45 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _grade_to_sign(10), _grade_to_exec(1)
{
}

Form::~Form()
{
}

Form::Form( const Form& other ) : _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
}

Form& Form::operator=( const Form& other )
{
    if ( this != &other )
        this->_signed = other._signed;
    return (*this);
}

Form::Form( std::string name, int signGrade, int execGrade ) :
    _name(name), _signed(false), _grade_to_sign(signGrade), _grade_to_exec(execGrade)
{
    const int i = this->get_g_t_sign();
    const int j = this->get_g_t_exec();
    if (i <= 0 || j <= 0)
        throw Form::GradeTooHighException();
    if (i > 150 || j > 150)
        throw Form::GradeTooLowException();
}

const std::string& Form::getName( void ) const { return this->_name; }
bool Form::getSign( void ) const { return this->_signed; }
int Form::get_g_t_sign( void ) const { return this->_grade_to_sign; }
int Form::get_g_t_exec( void ) const { return this->_grade_to_exec; }


void    Form::beSigned( const Bureaucrat& bureau )
{
    if ( bureau.getGrade() <= this->_grade_to_sign )
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

const char* Form::FormUnsignedException::what() const throw()
{
    return "Form::FormUnsignedException";
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return "Form::FormAlreadySigned";
}


std::ostream& operator<<(std::ostream& COUT, const Form& form)
{
    COUT << "📝: " << form.getName() << "; status: " << (form.getSign() ? "true" : "false")
         << "; grade required to sign: " << form.get_g_t_sign()
         << "; grade required to execute: " << form.get_g_t_exec();
    
    return COUT;
}
