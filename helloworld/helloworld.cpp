#include <iostream>
#define INPUT_LENGTH 100

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	std::cout << "Hello world!" << std::endl;
	std::cout << "Type some words and press enter : ";
	
	char userInput[INPUT_LENGTH];
	std::cin >> userInput;
	
	std::cout << "Your input is : " << userInput;
	std::cout << std::endl << "End of program";
	return(0);
}