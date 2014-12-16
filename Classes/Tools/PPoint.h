#ifndef P_POINT_H_
#define P_POINT_H_

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
};

#endif // P_POINT_H_
