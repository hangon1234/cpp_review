#include "calculator.h"

using namespace std;

void Calculator::Init()
{
	addOpCount = 0;
	divOpCount = 0;
	minOpCount = 0;
	timesOpCount = 0;
}

double Calculator::Add(double arg1, double arg2)
{
	addOpCount += 1;
	return (arg1 + arg2);
}

double Calculator::Div(double arg1, double arg2)
{
	divOpCount += 1;
	return (arg1 / arg2);
}

double Calculator::Min(double arg1, double arg2)
{
	minOpCount += 1;
	return (arg1 - arg2);
}

double Calculator::Times(double arg1, double arg2)
{
	timesOpCount += 1;
	return (arg1 * arg2);
}

void Calculator::ShowOpCount()
{
	cout << "Add : " << addOpCount << " Div : " << divOpCount << " Min: " 
	<< minOpCount << " Times : " << timesOpCount << endl;
}