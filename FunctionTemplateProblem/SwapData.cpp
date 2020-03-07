#include <iostream>

using namespace std;

class Point
{
	private:
	int xpos, ypos;
	public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

template<typename T>
void SwapData(T &arg1, T &arg2)
{
	T tempObj = arg1;
	arg1 = arg2;
	arg2 = tempObj;
}

int main(void)
{
	Point ptr1(1, 2);
	Point ptr2(3, 4);
	SwapData<Point>(ptr1, ptr2);
	ptr1.ShowPosition();
	ptr2.ShowPosition();
	return 0;
}