#include <iostream>
#include "bankingSystem.h"

using namespace std;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

Account * account[100];
int accountNumber;

void showMenu(int &choice);
void make();
void deposit();
void withdraw();
void inquire();

int main(void)
{
	int choice;
	
	while(1)
	{
		showMenu(choice);
		switch(choice)
		{
			case MAKE:
				make();
				break;
				
			case DEPOSIT:
				deposit();
				break;
				
			case WITHDRAW:
				withdraw();
				break;
				
			case INQUIRE:
				inquire();
				break;
				
			case EXIT:
				return(0);
				
			default:
				cout << "Wrong input!" << endl;
				break;
		}
	}
	
	return(0);
}

void showMenu(int &choice)
{
	cout << endl << "------Menu------" << endl;
	cout << "1. Make account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Inquire all account" << endl;
	cout << "5. Exit program" << endl;
	cout << " Choice: ";
	cin >> choice;
}

void make()
{
	cout << endl << "[Make account]" << endl;
	
	int accountID; int money; char customerName[100];
	
	cout << "Account ID : "; cin >> accountID;
	cout << "Customer name : "; cin >> customerName;
	cout << "Deposit amount : "; cin >> money; cout << endl;
	
	account[accountNumber++] = new Account(money, accountID, customerName);
}

void deposit()
{
	int accountID; int money;
	
	cout << endl << "[Deposit]" << endl;
	cout << "Account ID : "; cin >> accountID;
	cout << "Deposit amount : "; cin >> money;
	
	for(int i = 0; i < accountNumber; i++)
	{
		if(account[i]->showAccountID() == accountID)
		{
			account[i]->deposit(money);
			cout << "Deposit succeed" << endl;
			return;
		}
	}
	cout << "Invalid account ID" << endl;
}

void withdraw()
{
	cout << endl << "[Withdraw]" << endl;
	
	int accountID; int money;
	
	cout << "Account ID : "; cin >> accountID;
	cout << "Withdraw amount : "; cin >> money;
	
	for(int i = 0; i < accountNumber; i++)
	{
		if(account[i]->showAccountID() == accountID)
		{
			if(account[i]->checkBalance() <= money)
			{
				cout << "Insufficient balance" << endl;
				return;
			}else{
				account[i]->withdraw(money);
				return;
			}
		}
	}
	cout << "Invalid account ID" << endl;
}

void inquire()
{
	for(int i = 0; i < accountNumber; i++)
	{
		account[i]->inquire();
	}
}