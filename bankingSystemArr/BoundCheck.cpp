#include <iostream>
using namespace std;

class BoundCheckIntArray
{
	private:
		int * arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr) {}
		void operator=(const BoundCheckIntArray& arr) {}
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		int& operator[](int idx)
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[idx];
		}
		int operator[](int idx) const
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