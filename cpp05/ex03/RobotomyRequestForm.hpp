/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:56:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/30 20:38:49 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm( void );

    public:
        RobotomyRequestForm( std::string target );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm& src );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );

        virtual void execute( const Bureaucrat& executor ) const;
        virtual void action( const Bureaucrat& executor ) const;

};


# endif