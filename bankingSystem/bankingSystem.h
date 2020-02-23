#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

class Account
{
	public:
		Account(int money, int accountID, const char * customerName);
		~Account();
		void deposit(int money);
		void withdraw(int money);
		void inquire(void) const;
		int showAccountID(void) const;
		int checkBalance(void) const;
	
	private:
		char * customerName;
		int balance;
		int accountID;
};

#endif