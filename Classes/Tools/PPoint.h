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

public:
	PPoint(){};
	PPoint(float x, float y);
	float getX(){return _x; };
	float getY(){return _y; };
	float getXOriginal(){return _xOriginal; };
	float getYOriginal(){return _yOriginal; };
	void setPoint(float x, float y);
	CC_SYNTHESIZE(int, _xCell, XCell);
	CC_SYNTHESIZE(int, _yCell, YCell);
};

#endif // P_POINT_H_
