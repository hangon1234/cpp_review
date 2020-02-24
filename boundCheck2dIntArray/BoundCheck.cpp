#include <iostream>

using namespace std;

class BoundCheck2DIntArray
{
	private:
		int * arr;
		int arrlen;
		BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}\
		BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) { return *this; }
		
	public:
		BoundCheck2DIntArray(int len) : arrlen(len) { arr = new int[len]; }
		int& operator[] (int idx)
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[idx];
		}
		int operator[] (int idx) const
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "Array index out of bound exception" << endl;
				exit(1);
			}
			return arr[idx];
		}
		int GetArrLen() const { return arrlen; }
		~BoundCheck2DIntArray() {delete []arr; }
};

void ShowAllData(const BoundCheck2DIntArray& ref)
{
	int len = ref.GetArrLen();
	for(int idx=0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main(void)
{
	BoundCheck2DIntArray arr(5);
	for(int i =0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	ShowAllData(arr);
	return 0;
}

