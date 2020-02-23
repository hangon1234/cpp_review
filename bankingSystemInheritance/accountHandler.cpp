#include "bankingSystem.h"
#include <iostream>

using namespace std;

void AccountHandler::ShowMenu() const
{
	cout << "---------Menu---------" << endl;
	cout << "1. Create account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Show all account information" << endl;
	cout << "5. Terminate Program" << endl;
}

void AccountHandler::MakeAccount()
{
	int select;
	cout << "[Account type]" << endl;
	cout << "1. Normal account 2. High credit account" << endl;
	cout << "Select : " ;
	cin >> select;
	if(select == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID : "; cin >> id;
	cout << "Amount : "; cin >> money;
	
	for(int i = 0; i < accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "Transaction completed" << endl;
			return;
		}
	}
	cout << "Invalid account ID" << endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID : " ; cin >> id;
	cout << "Amount : "; cin >> money;
	for(int i = 0; i < accNum; i++)
	{
		if(accArr[i]->GetAccID() == id)
		{
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout << "Insufficient balance" << endl;
				return;
			}
			cout << "Transaction complete" << endl << endl;
			return;
		}
	}
	cout << "Invalid account ID" << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for(int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for(int i = 0; i < accNum; i++)
		delete accArr[i];
}

void AccountHandler::MakeNormalAccount()
{
	int accID;
	char name[NAME_LEN];
	int money;
	int rate;

	cout << "[Make normal account]" << endl;
	cout << "Account ID : "; cin >> accID;
	cout << "Name : "; cin >> name;
	cout << "Deposit :"; cin >> money;
	cout << "Interest rate: "; cin >> rate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(accID, money, name, rate);
}

void AccountHandler::MakeCreditAccount()
{
	int accID;
	char name[NAME_LEN];
	int money;
	int rate;
	int credit;

	cout << "[Make high credit account]" << endl;
	cout << "Account ID : "; cin >> accID;
	cout << "Name : "; cin >> name;
	cout << "Deposit : "; cin >> money;
	cout << "Interest rate : "; cin >> rate;
	cout << "Credit(1toA, 2toB, 3toC) : "; cin >> credit;
	cout << endl;

	switch(credit)
	{
		case 1:
			accArr[accNum++] = new HighCreditAccount(accID, money, name, rate, LEVEL_A);
			break;
		case 2:
			accArr[accNum++] = new HighCreditAccount(accID, money, name, rate, LEVEL_B);
			break;
		case 3:
			accArr[accNum++] = new HighCreditAccount(accID, money, name, rate, LEVEL_C);
			break;
	}
}
