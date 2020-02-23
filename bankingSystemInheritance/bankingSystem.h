#ifndef __BANKINGSYSTEM_H__
#define __BANKINGSYSTEM_H__

#define NAME_LEN 10

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};
enum {NORMAL=1, CREDIT=2};

class Account
{
	private:
		const int accID;
		int balance;
		char * cusName;

	public:
		Account(int ID, int money, char * name);
		Account(const Account & ref);

		int GetAccID() const;
		virtual void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
		~Account();
};

class NormalAccount : public Account
{
	private:
		const double interestRate;
	public:
		NormalAccount(int ID, int money, char * name, int rate)
		: Account(ID, money, name), interestRate(rate*0.01) {};
		virtual void Deposit(int money);
};

class HighCreditAccount : public NormalAccount
{
	private:
		const double spcRate;
	public:
		HighCreditAccount(int ID, int money, char * name, int rate, int spcRate)
		: NormalAccount(ID, money, name, rate), spcRate(spcRate*0.01) {};
		virtual void Deposit(int money);
};

class AccountHandler
{
	private:
		Account * accArr[100];
		int accNum;

	public:
		AccountHandler() : accNum(0) {};
		void ShowMenu() const;
		void MakeAccount();
		void DepositMoney();
		void WithdrawMoney();
		void ShowAllAccInfo() const;
		~AccountHandler();

	protected:
		void MakeNormalAccount();
		void MakeCreditAccount();
};
#endif
