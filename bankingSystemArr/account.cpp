#include <iostream>
#include <cstring>
#include "bankingSystem.h"

using namespace std;

Account::Account(int ID, int money, char * name)
: accID(ID), balance(money)
{
	cusName = new char[sizeof(name)+1];
	strcpy(cusName, name);
}

Account::Account(const Account & ref)
: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[sizeof(ref.cusName)+1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if(money > balance)
		return 0;
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "Acc ID : " << accID << endl;
	cout << "Name : " << cusName << endl;
	cout << "Balance : " << balance << endl;
}

Account::~Account(){ delete []cusName; }

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money + (money * interestRate));
}

void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money);
	Account::Deposit(money * spcRate);
}