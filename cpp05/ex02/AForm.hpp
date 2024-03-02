/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:15:00 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/02 15:14:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP

# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string  _name;
        bool               _signed;
        const int          _grade_to_sign;
        const int          _grade_to_exec;

        AForm( void );
        
    public:
        virtual ~AForm( void );
        AForm( const AForm& other );
        AForm& operator=( const AForm& other );

        AForm( std::string name, int signGrade, int execGrade );


        // getters
        const std::string& getName( void ) const;
        bool               getSign( void ) const;
        int                get_g_t_sign( void ) const;
        int                get_g_t_exec( void ) const;

        
        void         beSigned( const Bureaucrat& bureau );

        bool         authentication( const Bureaucrat& bureau, const AForm& form ) const;
        virtual void execute( const Bureaucrat& executor ) const = 0;
        virtual void action(const Bureaucrat& executor) const = 0;

        
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        class FormUnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

		class FormAlreadySigned : public std::exception
		{
			public: 
				virtual const char* what() const throw();
		};
        
};


std::ostream& operator<<(std::ostream& COUT, const AForm& form);


# endif

