/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:59:22 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/05 20:31:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm("Robotomy", 72, 45)
{
	this->_target = src._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs )
{
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

void    RobotomyRequestForm::action( const Bureaucrat& executor ) const
{
    srand(time(0));
    executor.getName();
    std::cout << "I say, Lois, this diabolically ingenious drilling apparatus is making more noise than a symphony of jackhammers at dawn, wouldn't you agree?" << std::endl;
    std::cout << std::endl;
    
    if (rand() % 2 == 0)
		std::cout << "Ah, splendid! It appears that our dear subject, " << this->_target <<" , has been robotomized with impeccable precision. A triumph of technology and wit, indeed" << std::endl;
	else
		std::cout << "Blast! Despite our valiant efforts, it seems that " << this->_target << "has eluded the grasp of robotomization. A most unfortunate and vexing turn of events, to say the least." << std::endl;
}

void    RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	authentication( executor, *this );
	action( executor );
}