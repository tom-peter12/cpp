/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:54:41 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/08 14:07:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
		Bureaucrat( void );
		
	public:
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& other );
		
		Bureaucrat&	operator=( const Bureaucrat& other );

		Bureaucrat( std::string name, int grade );

		
		const std::string&	getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( int incr_value = 1 );
		void				decrementGrade( int decr_value = 1 );
		
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

		class IncrementValueTooLow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& COUT, const Bureaucrat& bureau);

# endif