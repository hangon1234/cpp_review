#include <iostream>
#include <cstring>
#include "bankingSystem.h"

using namespace std;

Account::Account(int money, int accountID, const char * customerName)
: balance(money), accountID(accountID)
{
	this->customerName = new char[strlen(customerName)+1];
	strcpy(this->customerName, customerName);
}

Account::~Account()
{
	delete []customerName;
}

void Account::deposit(int money)
{
	balance += money;
}

void Account::withdraw(int money)
{
	balance -= money;
}

void Account::inquire(void) const
{
	cout << "Account ID : " << accountID << endl;
	cout << "Customer Name : " << customerName << endl;
	cout << "Balance : " << balance << endl << endl; 
}

int Account::showAccountID(void) const
{
	return accountID;
}

int Account::checkBalance(void) const
{
	return balance;
}