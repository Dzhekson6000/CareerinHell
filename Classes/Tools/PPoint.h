#ifndef P_POINT_H_
#define P_POINT_H_
#include "cocos2d.h"

class PPoint
{
private:
	//изометрические координаты
	float _x;
	float _y;
	//реальные координаты
	float _xOriginal;
	float _yOriginal;
	void updateIsometric();

public:
	PPoint(){};
	PPoint(float x, float y);
	PPoint(int x, int y);
	float getX(){return _x; };
	float getY(){return _y; };
	float getXOriginal(){return _xOriginal; };
	float getYOriginal(){return _yOriginal; };
	int getXCell();
	int getYCell();
	void setXCell(int x);
	void setYCell(int y);
	void setPoint(float x, float y);
};

#endif // P_POINT_H_
