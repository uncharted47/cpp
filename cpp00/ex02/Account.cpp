/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:34:04 by elyzouli          #+#    #+#             */
/*   Updated: 2024/10/21 18:34:19 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

 int Account::_nbAccounts = 0;
 int Account::_totalAmount = 0;
 int Account::_totalNbDeposits = 0;
  int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	std::cout << "] ";
}


Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;

}

Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}


void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int		Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}


int		Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}
