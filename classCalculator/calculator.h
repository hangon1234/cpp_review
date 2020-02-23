#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
using namespace std;

class Calculator
{
	private:
		unsigned int addOpCount;
		unsigned int divOpCount;
		unsigned int minOpCount;
		unsigned int timesOpCount;
		
	public:
		void Init();
		double Add(double arg1, double arg2);
		double Div(double arg1, double arg2);
		double Min(double arg1, double arg2);
		double Times(double arg1, double arg2);
		void ShowOpCount();
};

#endif