#include "PPoint.h"

PPoint::PPoint(float x, float y)
{
	setPoint(x,y);
}

PPoint::PPoint( int x, int y )
{
	setPoint(x*50,y*50);
}

void PPoint::setPoint(float x, float y)
{
	_xOriginal = x;
	_yOriginal = y;
	updateIsometric();
}

int PPoint::getXCell()
{
	return floor(_xOriginal/50);
}

int PPoint::getYCell()
{
	return floor(_yOriginal/50);
}

void PPoint::setXCell(int x)
{
	_xOriginal = x*50;
	updateIsometric();
}

void PPoint::setYCell(int y)
{
	_yOriginal = y*50;
	updateIsometric();
}

void PPoint::updateIsometric()
{
	_x = _xOriginal-_yOriginal;
	_y = (_xOriginal+_yOriginal)/2;
}
