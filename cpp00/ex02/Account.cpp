#include "Account.hpp"
#include <string>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account:: Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _totalAmount += initial_deposit;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:", std::cout << _accountIndex, std::cout << ";";
    std::cout << "amount:", std::cout << _amount, std::cout << ";";
    std::cout << "created" << std::endl;
    return;
}

Account:: ~Account(void)
{
    _displayTimestamp();
    std::cout << "index:", std::cout << _accountIndex, std::cout << ";";
    std::cout << "amount:", std::cout << _amount, std::cout << ";";
    std::cout << "closed" << std::endl;
    return;
} 

void	Account::_displayTimestamp( void )
{
    std::cout << "[19920104_091532] ";
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:", std::cout << _nbAccounts, std::cout << ";";
    std::cout << "total:", std::cout << _totalAmount, std::cout << ";";
    std::cout << "deposits:", std::cout << _totalNbDeposits, std:: cout << ";";
    std::cout << "withdrawals:", std::cout << _totalNbWithdrawals << std::endl;

}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:", std::cout << _accountIndex, std::cout << ";";
    std::cout << "amount:", std::cout << _amount, std::cout << ";";
    std::cout << "deposits:", std::cout << _nbDeposits, std::cout << ";";
    std::cout << "withdrawals:", std::cout << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:", std::cout << _accountIndex, std::cout << ";";
    std::cout << "p_amount:", std::cout << _amount, std::cout << ";";
    std::cout << "deposit:", std::cout << deposit, std::cout << ";";
    
    _amount += deposit;
    std::cout << "amount:", std::cout << _amount, std::cout << ";";

    _nbDeposits++;
    std::cout << "nb_deposits:", std::cout << _nbDeposits << std::endl;

    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:", std::cout << _accountIndex, std::cout << ";";
    std::cout << "p_amount:", std::cout << _amount, std::cout << ";";

    if (_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        std::cout << "withdrawal:", std::cout << withdrawal, std::cout << ";";
        _amount -= withdrawal;
        std::cout << "amount:", std::cout << _amount, std::cout << ";";

        _nbWithdrawals++;
        std::cout << "nb_withdrawals:", std::cout << _nbWithdrawals << std::endl;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }    
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}
