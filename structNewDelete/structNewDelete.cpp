#include <iostream>

using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *result = new Point;
	(*result).xpos = p1.xpos + p2.xpos;
	(*result).ypos = p1.ypos + p2.ypos;
	return *result;
}

int main(void)
{
	Point *ptrFirstPoint = new Point;
	cout << "input first X position : ";
	cin >> ptrFirstPoint->xpos;
	cout << "input second Y position : ";
	cin >> ptrFirstPoint->ypos;
	
	Point *ptrSecondPoint = new Point;
	cout << "input first X position : ";
	cin >> ptrSecondPoint->xpos;
	cout << "input second Y position : ";
	cin >> ptrSecondPoint->ypos;
		
	Point &result = PntAdder(*ptrFirstPoint, *ptrSecondPoint);
	
	cout << "X position : " << result.xpos << " Y position : " << result.ypos << endl;
	
	delete ptrFirstPoint;
	delete ptrSecondPoint;
	delete &result;
	
	return 0;
}