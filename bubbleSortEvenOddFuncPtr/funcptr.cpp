/*
 *
 * Bubble sort algorithm
 * Sort by ascending order 
 * but should differenciate odd and even data
 * For example, assume we have data
 * [3,2,1,4,6,8,7,5,3,4,5]
 * after sort, it should be same as following sequence:
 * [1,3,3,5,5,7,2,4,4,6,8]
 * Remember, odd numbers should be placed before even numbers
 * 
 */

#include <iostream>
using namespace std;

int ACDSortOddLeft(int num1, int num2);
void BubbleSort(int arr[], int len, int (*sortFunc)(int, int));

int main(void)
{
	int arr1[] = {3,2,1,4,6,8,7,5,3,4,5};
	
	BubbleSort(arr1, sizeof(arr1)/sizeof(int), ACDSortOddLeft);
	
	for(int i = 0; i < sizeof(arr1)/sizeof(int); i++)
		cout << arr1[i] << " ";
	cout << endl;
	
	return 0;
}

int ACDSortOddLeft(int num1, int num2)
{ 
	if((num1%2) == 0 && (num2%2) != 0)
		return 1;
	if((num1%2) != 0 && (num2%2) == 0)
		return 0;
	if(num1 > num2)
		return 1;
	else
		return 0;
}

void BubbleSort(int arr[], int len, int(*sortFunc)(int, int))
{
	int tmp;
	
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len-1; j++)
		{
			if(sortFunc(arr[j], arr[j+1]))
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}