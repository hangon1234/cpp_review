#include "classEncapsulationRing.h"

using namespace std;

// Point class
void Point::Init(int x, int y)
{
	xpos = x;
	ypos = y;
}

void Point::ShowPointInfo() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

// Circle class
void Circle::Init(int argRadius, int xpos, int ypos)
{
	circlePoint.Init(xpos, ypos);
	radius = argRadius;
}

void Circle::ShowRadius()
{
	cout << "radius: " << radius << endl;
}

void Circle::ShowCirclePoint()
{
	circlePoint.ShowPointInfo();
}

// Ring class
void Ring::Init(int innerCircleX, int innerCircleY, int innerCircleRadius,
int outerCircleX, int outerCircleY, int outerCircleRadius)
{
	innerCircle.Init(innerCircleRadius, innerCircleX, innerCircleY);
	outerCircle.Init(outerCircleRadius, outerCircleX, outerCircleY);
}

void Ring::ShowRingInfo()
{
	cout << "Inner circle info..." << endl;
	innerCircle.ShowRadius();
	innerCircle.ShowCirclePoint();
	
	cout << "Outter circle info..." << endl;
	outerCircle.ShowRadius();
	outerCircle.ShowCirclePoint();
}