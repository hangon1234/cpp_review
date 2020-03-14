#include <iostream>

using namespace std;

int main(void)
{
	int i = 1;
	try{
		while(1)
		{
			i++;
			new int[10][10];
		}
	}
	catch(bad_alloc &bad)
	{
		cout << bad.what() << endl;
		cout << "Program dead after " << i << "th allocation" << endl;
		cout << "exception!" << endl;
	}
	return 0;
}
