#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();

	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_totalAmount += this->_amount;

	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:" 	<< this->_amount
				<< ";created" 	<< std::endl; 
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:"		<< Account::getNbAccounts()
				<< ";total:" 		<< Account::getTotalAmount()
				<< ";deposits:" 	<< Account::getNbDeposits()
				<< ";withdrawals:"	<< Account::getNbWithdrawals()
				<< std::endl; 
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";p_amount:" 	<< this->_amount
				<< ";deposit:" 		<< deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout	<< ";amount:"		<< this->_amount
				<< ";nb_deposits:" 	<< this->_nbDeposits
				<< std::endl; 

	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";p_amount:" 	<< this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout	<< ";withdrawal:"		<< withdrawal
					<< ";amount:"			<< this->_amount
					<< ";nb_withdrawals:" 	<< this->_nbWithdrawals
					<< std::endl; 

		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		return (true);
	}
}


void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex
				<< ";amount:" 		<< this->_amount
				<< ";deposits:" 	<< this->_nbDeposits
				<< ";withdrawals:"	<< this->_nbWithdrawals
				<< std::endl; 
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//static void	double_digit(int time)
//{
//	if (time < 10)
//		std::cout << 0 << time;
//	else
//		std::cout << time;
//}		
//
//void	Account::_displayTimestamp(void)
//{
//	time_t		ttNow = time(0);
//	tm			*now;
//
//	now = localtime(&ttNow);
//	std::cout << "[" << 1900 + now->tm_year;
//	double_digit(1 + now->tm_mon);
//	double_digit(now->tm_mday);
//	std::cout << "_";
//	double_digit(now->tm_hour);
//	double_digit(now->tm_min);
//	double_digit(now->tm_sec);
//	std::cout << "] ";
//}


void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}


Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex
				<< ";amount:" 	<< this->_amount
				<< ";closed" 	<< std::endl; 
}
