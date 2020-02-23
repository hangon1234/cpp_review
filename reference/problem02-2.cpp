// Problem 02-2
// const pointer and const reference
// Book page 90

/*

const 포인터에 대한 복습을 겸할 수 있는 문제를 제시하겠다. 다음의 상수선언을 보자.
  const int num=12;
  
포인터 변수를 선언해서 위 변수를 가리키게 해보자. 그리고 이 포인터 변수를 참조하는 참조자를
하나 더 선언하자. 마지막으로 이렇게 선언된 포인터 변수와 참조라를 이용해서 num에 저장된 값을
출력하는 예제를 완성해보자.

*/

#include <iostream>

using namespace std;

int main(void)
{
	const int num = 12;
	const int *ptrNum = &num;
	const int &refNum = *ptrNum;
	
	cout << "num : " << num << endl;
	cout << "*ptrNum : " << *ptrNum << endl;
	cout << "&refNum : " << refNum << endl;
	
	return(0);
}