#ifndef __CLASSENCAPSULATIONRING_H__
#define __CLASSENCAPSULATIONRING_H__

#include <iostream>

using namespace std;

class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x, int y);
		void ShowPointInfo() const;
};

class Circle
{
	private:
		Point circlePoint;
		int radius;
	public:
		Circle(int argRadius, int xpos, int ypos);
		void ShowRadius();
		void ShowCirclePoint();
};

class Ring
{
	private:
		Circle innerCircle;
		Circle outerCircle;
		
	public:
		Ring(int innerCircleX, int innerCircleY, int innerCircleRadius,
		int outerCircleX, int outerCircleY, int outerCircleRadius);
		void ShowRingInfo(void);
};

#endif