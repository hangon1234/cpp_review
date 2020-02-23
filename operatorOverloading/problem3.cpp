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
		friend bool operator==(const Point &ptr1, const Point &ptr2);
		friend bool operator!=(const Point &ptr1, const Point &ptr2);
};

bool operator==(const Point &ptr1, const Point &ptr2)
{
	if(ptr1.xpos == ptr2.xpos && ptr1.ypos == ptr2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point &ptr1, const Point &ptr2)
{
	return !(ptr1==ptr2);
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(3, 4);
	
	cout << "pos1 == pos2 : " << (pos1 == pos2) << endl;
	cout << "pos1 != pos2 : " << (pos1 != pos2) << endl;
	
	Point pos3(3, 4);
	Point pos4(3, 5);
	
	cout << "pos3 == pos4 : " << (pos3 == pos4) << endl;
	cout << "pos3 != pos4 : " << (pos3 != pos4) << endl;
	
	return 0;
}