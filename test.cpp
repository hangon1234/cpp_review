#include <iostream>

using namespace std;

void func1()
{
	cout << "Hey! this is a function" << endl;
}
void func2()
{
	cout << "Hey! this is a second function" << endl;
}
int main(void)
{
	cout << "func1 address: " << func1 << endl;
	cout << "func2 address: " << func2 << endl;
	return 0;
}