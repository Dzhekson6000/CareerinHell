#include "PPoint.h"

PPoint::PPoint(float x, float y)
{
	setPoint(x,y);
}

void PPoint::setPoint(float x, float y)
{
	_xOriginal = x;
	_yOriginal = y;
	_x = x-y;
	_y = (x+y)/2;
}