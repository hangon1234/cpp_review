#include <iostream>

using namespace std;

class Rectangle
{
	private:
		int xlen, ylen;
	public:
		void ShowAreaInfo();
		Rectangle(int xlen, int ylen) : xlen(xlen), ylen(ylen) {}
};

void Rectangle::ShowAreaInfo()
{
	cout << "Area : " << xlen * ylen << endl;
}

class Square : public Rectangle
{
	public:
		Square(int len) : Rectangle(len, len) {}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	
	return 0;
}