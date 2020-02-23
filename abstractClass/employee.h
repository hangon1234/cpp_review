#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

namespace RISK_LEVEL{
	enum {RISK_A = 3, RISK_B = 2, RISK_C = 1};
}

class Employee
{
	private:
		char name[100];
	public:
		Employee(const char * name);
		void ShowYourName() const;
		virtual int GetPay() const = 0;
		virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
	private:
		int salary;
	public:
		PermanentWorker(const char * name, int money) 
		: Employee(name), salary(money){};
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
};

class SalesWorker : public PermanentWorker
{
	private:
		int salesResult;
		double bonusRatio;
	public:
		SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){};
		void AddSalesResult(int value);
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
};

class ForeignSalesWorker : public SalesWorker
{
	private:
		double riskLevel;
	public:
		ForeignSalesWorker(const char * name, int money, double ratio, double riskLevel)
		: SalesWorker(name, money, ratio), riskLevel(riskLevel * 0.1){};
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
		int GetRiskPay() const;
};

class EmployeeHandler
{
	private:
		Employee * empList[50];
		int empNum;
		
	public:
		EmployeeHandler() : empNum(0){};
		void AddEmployee(Employee * emp);
		void ShowAllSalaryInfo() const;
		void ShowTotalSalary() const;
		~EmployeeHandler();
};


#endif