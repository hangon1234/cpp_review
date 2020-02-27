#include <iostream>
using namespace std;
#include "bankingSystem.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
	private:
		ACCOUNT_PTR * arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr) {}
		void operator=(const BoundCheckIntArray& arr) {}
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		ACCOUNT_PTR& operator[](int idx)
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[idx];
		}
		ACCOUNT_PTR operator[](int idx) const
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[idx];
		}
		int GetArrLen() const
		{
			return arrlen;
		}
		~BoundCheckIntArray()
		{
			delete []arr;
		}
};