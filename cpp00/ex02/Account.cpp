/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:29:12 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/26 19:45:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{	
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout <<  " index:"<< _accountIndex << ";amount:"
			  << this->_amount << ";created" << std::endl;
	_nbAccounts = _nbAccounts + 1;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout <<  " index:"<< this->_accountIndex << ";amount:"
			  << this->_amount << ";created" << std::endl;
	_totalAmount = _totalAmount + this->_amount;
	_nbAccounts++;
	
}

Account::~Account()
{
	_displayTimestamp();
	std::cout <<  " index:"<< this->_accountIndex << ";amount:"
			  << this->_amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int	Account::getTotalAmount( void ) { return Account::_totalAmount; }

int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals ; }




void	Account::makeDeposit( int deposit )
{
	int tmp;
	tmp = this->_amount;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout <<  " index:"<< this->_accountIndex << ";p_amount:" << tmp
			  << ";deposit:" << deposit << ";amount:" << this->_amount 
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) 
{
	int tmp;
	tmp = this->_amount;
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout <<  " index:"<< this->_accountIndex << ";p_amount:" << tmp
			  << ";withdrawal:" << withdrawal << ";amount:" << this->_amount 
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout <<  " index:" << this->_accountIndex << ";p_amount:" << tmp
			  << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount( void ) const 
{ 
	return (this->_amount); 
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" 
			  << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<  " index:"<< this->_accountIndex << ";amount:"
			  << this->_amount << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

