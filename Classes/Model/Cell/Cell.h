#ifndef CELL_H__
#define CELL_H__
#include "cocos2d.h"
#include "Tools/PPoint.h"
#include "Common/common.h"

USING_NS_CC;

class Cell
{
private:
	int _width;
	int _height;
	int _xCenter;
	int _yCenter;
	bool _inversionX;
	bool _inversionY;
	int getInverse(bool inversion);
protected:
	int _order;
	PPoint* _point;
	Sprite* _sprite;
	void createSprite(std::string textureName);
public:
	Cell(PPoint* point);
	PPoint* getPosition();
	Sprite* getTexture();

	void setSize(int width, int height);
	void setCenter(int xCenter, int yCenter);
	void setPosition(PPoint* point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	int getOrder(){ return _order; }

	virtual void click(){};

};
#endif // CELL_H__