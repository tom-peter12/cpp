/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:15:00 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/04 14:17:20 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP

# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string  _name;
        bool               _signed;
        const int          _grade_to_sign;
        const int          _grade_to_exec;

        Form( void );
        
    public:
        ~Form( void );
        Form( const Form& other );
        Form& operator=( const Form& other );

        Form( std::string name, int signGrade, int execGrade );


        // getters
        const std::string& getName( void ) const;
        bool               getSign( void ) const;
        int                get_g_t_sign( void ) const;
        int                get_g_t_exec( void ) const;

        
        void               beSigned( const Bureaucrat& bureau );
        
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


std::ostream& operator<<(std::ostream& COUT, const Form& form);


# endif

