#include "employee.h"
#include <iostream>
#include <cstring>

using namespace std;

Employee::Employee(const char * name)
{
	strcpy(this->name, name);
}

void Employee::ShowYourName() const
{
	cout << "Name : " << name << endl;
}

int PermanentWorker::GetPay() const
{
	return salary;
}

void PermanentWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary : " << GetPay() << endl << endl;
}

void SalesWorker::AddSalesResult(int value)
{
	salesResult += value;
}

int SalesWorker::GetPay() const
{
	return PermanentWorker::GetPay() +
			(int)(salesResult*bonusRatio);
}

void SalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary : " << GetPay() << endl << endl;
}

int ForeignSalesWorker::GetPay() const
{
	return SalesWorker::GetPay() + (int)(SalesWorker::GetPay() * riskLevel);
}

int ForeignSalesWorker::GetRiskPay() const
{
	return (int)(SalesWorker::GetPay() * riskLevel);
}

void ForeignSalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "Salary : " << SalesWorker::GetPay() << endl;
	cout << "Risk  Pay : " << GetRiskPay() << endl;
	cout << "Sum : " << GetPay() << endl << endl;
}

void EmployeeHandler::AddEmployee(Employee *emp)
{
	empList[empNum++]  = emp;
}

void EmployeeHandler::ShowAllSalaryInfo() const
{
	for(int i = 0; i < empNum; i++)
	{
		empList[i]->ShowSalaryInfo();
	}
}

void EmployeeHandler::ShowTotalSalary() const
{
	int totalSalary = 0;
	for(int i = 0; i < empNum; i++)
	{
		totalSalary += empList[i]->GetPay();
	}
	cout << "Total pay : " << totalSalary << endl << endl;
}

EmployeeHandler::~EmployeeHandler()
{
	for(int i = 0; i < empNum; i++)
	{
		delete []empList[i];
	}
}