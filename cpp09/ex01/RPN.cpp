/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:06 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/17 15:46:10 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

std::stack<int> RPN::_rpn_stack;

int RPN::do_rpn( const std::string& ops )
{
	if (ops.empty())
		throw RPN::NotEnoughOperands();
	const char operators[5] = "+-/*";
	int temp;
	for (std::string::const_iterator it = ops.begin(); it != ops.end(); ++it)
	{
		if (std::isdigit(*it))
		{
			if (std::isdigit(*(it + 1)))
				throw RPN::InvalidCharacterInOperands();
			_rpn_stack.push(*it - '0');
		}
		else if (std::strchr(operators, *it))
		{
			if (_rpn_stack.size() < 2)
				throw (RPN::NotEnoughOperands());
			temp = _rpn_stack.top();
			_rpn_stack.pop();
			switch (*it)
			{
				case '+':
					_rpn_stack.top() = _rpn_stack.top() + temp;
					break;
				case '-':
					_rpn_stack.top() = _rpn_stack.top() - temp;
					break;
				case '/':
					if (temp == 0)
						throw (RPN::DivisionByZeroException());
					_rpn_stack.top() = _rpn_stack.top() / temp;
					break;
				case '*':
					_rpn_stack.top() = temp * _rpn_stack.top();
					break;
				
				default:
					break;
			}
		}
		else if (std::isspace(*it))
			continue ;
		else
			throw RPN::InvalidCharacterInOperands();
	}
	if (_rpn_stack.size() > 1)
		throw (RPN::NotEnoughOperators());
	
	return (_rpn_stack.top());
}

const char *RPN::NotEnoughOperators::what() const throw()
{
	return ("RPN::NotEnoughOperators");
}

const char *RPN::NotEnoughOperands::what() const throw()
{
	return ("RPN::NotEnoughOperands");
}

const char *RPN::InvalidCharacterInOperands::what() const throw()
{
	return ("RPN::InvalidCharacterInOperands");
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("RPN::DivisionByZeroException");
}