/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:50:32 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/30 20:51:42 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP


# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm( void );

    public:
        PresidentialPardonForm( std::string target );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm( const PresidentialPardonForm& src );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

        virtual void execute( const Bureaucrat& executor ) const;
        virtual void action( const Bureaucrat& executor ) const;

};


# endif