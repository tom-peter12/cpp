/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:54:28 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/05 20:31:08 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubery", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm("Shrubery", 145, 137)
{
	this->_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs )
{
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}

void    ShrubberyCreationForm::action( const Bureaucrat& executor ) const
{
		std::ofstream outputFile((this->_target + "_shrubbery.txt").c_str());
		if (!outputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
		}

		outputFile << "            .        +          .      .          . \n";
		outputFile << "     .            _        .                    .\n";
		outputFile << "  ,              /;-._,-.____        ,-----.__\n";
		outputFile << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n";
		outputFile << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n";
		outputFile << "                      ,    `./  \\:. `.   )==-'  .\n";
		outputFile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n";
		outputFile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n";
		outputFile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n";
		outputFile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n";
		outputFile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n";
		outputFile << "              \\:  `  X` _| _,\\/`   .-'\n";
		outputFile << ".               \":._:`\\____  /:'  /      .           .\n";
		outputFile << "                    \\::.  :\\/:'  /              +\n";
		outputFile << "   .                 `.:.  /:'  }      .\n";
		outputFile << "           .           ):_(:;   \\           .\n";
		outputFile << "                      /:. _/ ,  |\n";
		outputFile << "                   . (|::.     ,`                  .\n";
		outputFile << "     .                |::.    {\\ \n";
		outputFile << "                      |::.\\  \\ `.\n";
		outputFile << "                      |:::(\\    |\n";
		outputFile << "              O       |:::/{ }  |                  (o\n";
		outputFile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n";
		outputFile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
		outputFile << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n";

		outputFile << "\nSigned by: " << executor.getName()<<std::endl;
		outputFile.close();
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	authentication( executor, *this );
	action( executor );
}