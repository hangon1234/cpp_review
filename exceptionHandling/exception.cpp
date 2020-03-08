#include <iostream>

using namespace std;

void func1(int arg);
void func2(int arg);

void func1(int arg)
{
	cout << "func1" << endl;
	func2(arg);
}

void func2(int arg)
{
	cout << "func2" << endl;
	throw arg;
}

int main(void)
{
	cout << "Calling func1" << endl;
	try{
		func1(100);
	}
	catch(int arg){
		cout << "exception catched" << endl;
		cout << "arg: " << arg << endl;
	}
	return 0;
}