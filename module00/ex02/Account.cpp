#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
  static int index = 0;

  _accountIndex = index;
  index++;
  _nbAccounts++;
  _totalAmount += _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "Amount:" << _amount << ";"
            << "created" << std::endl;
}
Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "Amount:" << _amount << ";"
            << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void) {
  std::time_t currentTime = std::time(NULL);
  std::tm *now = std::localtime(&currentTime);

  char fTime[19];
  std::strftime(fTime, sizeof(fTime), "[%Y%m%d_%H%M%S] ", now);
  std::cout << fTime;
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";"
            << "total:" << getTotalAmount() << ";"
            << "deposits:" << getNbDeposits() << ";"
            << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  _totalAmount += deposit;
  _amount += deposit;
  _nbDeposits += 1;
  _totalNbDeposits += 1;
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount - deposit << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused" << std::endl;
    return false;
  }
  _totalAmount -= withdrawal;
  _amount -= withdrawal;
  _nbWithdrawals += 1;
  _totalNbWithdrawals += 1;
  std::cout << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount(void) const { return _amount; }
