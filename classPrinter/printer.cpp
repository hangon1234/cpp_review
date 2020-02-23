#include "printer.h"
#include <cstring>

using namespace std;

void Printer::SetString(const char *arg)
{
	strcpy(string, arg);
}

void Printer::ShowString()
{
	cout << string << endl;
}