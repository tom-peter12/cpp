/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:26:43 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/05 21:12:06 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _grade_to_sign(10), _grade_to_exec(1)
{
}

AForm::~AForm()
{
}

AForm::AForm( const AForm& other ) : _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
}

AForm& AForm::operator=( const AForm& other )
{
    if ( this != &other )
        this->_signed = other._signed;
    return (*this);
}

AForm::AForm( std::string name, int signGrade, int execGrade ) :
    _name(name), _signed(false), _grade_to_sign(signGrade), _grade_to_exec(execGrade)
{
    const int i = this->get_g_t_sign();
    const int j = this->get_g_t_exec();
    if (i <= 0 || j <= 0)
        throw AForm::GradeTooHighException();
    if (i > 150 || j > 150)
        throw AForm::GradeTooLowException();
}

const std::string& AForm::getName( void ) const { return this->_name; }
bool AForm::getSign( void ) const { return this->_signed; }
int AForm::get_g_t_sign( void ) const { return this->_grade_to_sign; }
int AForm::get_g_t_exec( void ) const { return this->_grade_to_exec; }


void    AForm::beSigned( const Bureaucrat& bureau )
{
	if (this->getSign() == true)
	{
		throw AForm::FormAlreadySigned();
		return ;
	}
    if ( bureau.getGrade() <= this->_grade_to_sign )
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

bool    AForm::authentication( const Bureaucrat& bureau, const AForm& form ) const
{
    if (form.getSign() == false)
        throw AForm::FormUnsignedException();
    if (bureau.getGrade() > form.get_g_t_exec())
        throw AForm::GradeTooLowException();
    return true;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char* AForm::FormUnsignedException::what() const throw()
{
    return "AForm::FormUnsignedException";
}

const char* AForm::FormAlreadySigned::what() const throw()
{
	return "AForm::FormAlreadySigned";
}



std::ostream& operator<<(std::ostream& COUT, const AForm& form)
{
    COUT << "📝: " << form.getName() << "; status: " << (form.getSign() ? "true" : "false")
         << "; grade required to sign: " << form.get_g_t_sign()
         << "; grade required to execute: " << form.get_g_t_exec();
    
    return COUT;
}
