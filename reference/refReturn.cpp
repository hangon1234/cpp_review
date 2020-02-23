#include <iostream>

using namespace std;

// return refererence
int & returnRefAddTen(int &ref)
{	
	// return reference and this is wrong
	// only display compiler warning
	// return local variable as reference
	
	int num = 10 + ref;
	
	return(num);  // num will be expired!
}

// return reference's value
int returnValAddTen(int &ref)
{
	// return value
	return(ref + 10);
}

int main(void)
{
	int num = 100;
	cout << "num : " << num << endl;
	
	int numVal = returnValAddTen(num);
	cout << "numVal : " << numVal << endl;
	
	// it can be work correctly
    // but actually wrong!
	// win10 failed to display numRef correctly
	int &numRef = returnRefAddTen(num);
	cout << "numRef : " << numRef << endl;
	
	return(0);
}