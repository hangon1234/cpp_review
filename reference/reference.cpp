#include<iostream>

using namespace std;

int main(void)
{
	int number = 100;
	int * ptrNumber = &number;
	int & refNumber = number;
	
	cout << "Number's value : " << number << endl;
	cout << "ptrNumber's value : " << *ptrNumber << endl;
	cout << "refNumber's value : " << refNumber << endl;
	
	cout << "Add 1 to number variable " << endl;
	number += 1;
	cout << "Number's value : " << number << endl;
	
	cout << "Add 1 to ptrNumber" << endl;
	*ptrNumber += 1;
	cout << "ptrNumber's value : " << *ptrNumber << endl;
	
	cout << "Add 1 to refNumber" << endl;
	cout << "refNumber's value : " << refNumber << endl;
	
	cout << endl << "Number : " << number << " ptrNumber : " << *ptrNumber <<
	" refNumber : " << refNumber << endl;
	
	cout << "End of program..." << endl;
	
	return(0);
}