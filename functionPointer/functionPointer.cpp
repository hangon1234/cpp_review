#include <iostream>

using namespace std;

void function(){ cout << "function called" << endl; }

int main(void)
{
	void (*PtrFunc)();
	
	PtrFunc = function;
	// is also equivalent 
	// PtrFunc = &function;
	
	//invoking function() using PtrFunc
	PtrFunc();
	//is also equivalent as above
	(*PtrFunc)();
	return 0;
}