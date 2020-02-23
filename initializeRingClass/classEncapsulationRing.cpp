#include "classEncapsulationRing.h"

using namespace std;

// Point class
Point::Point(int x, int y)
{
	xpos = x;
	ypos = y;
}

void Point::ShowPointInfo() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

// Circle class
Circle::Circle(int argRadius, int xpos, int ypos)
: circlePoint(xpos, ypos)
{
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
Ring::Ring(int innerCircleX, int innerCircleY, int innerCircleRadius,
int outerCircleX, int outerCircleY, int outerCircleRadius)
: innerCircle(innerCircleRadius, innerCircleX, innerCircleY),
  outerCircle(outerCircleRadius, outerCircleX, outerCircleY)
{}

void Ring::ShowRingInfo()
{
	cout << "Inner circle info..." << endl;
	innerCircle.ShowRadius();
	innerCircle.ShowCirclePoint();
	
	cout << "Outter circle info..." << endl;
	outerCircle.ShowRadius();
	outerCircle.ShowCirclePoint();
}