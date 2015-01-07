#ifndef CELL_H__
#define CELL_H__
#include "cocos2d.h"
#include "Tools/PPoint.h"

USING_NS_CC;

#define defaultImage "img/defaultImage.png"

class Cell
{
private:
	int _width;
	int _height;
	bool _inversionX;
	bool _inversionY;
	void updateInversion();
protected:
	int _order;
	PPoint* _point;
	Sprite* _sprite;
	void createSprite(std::string textureName);
public:
	Cell(PPoint* point);
	PPoint* getPosition();
	Sprite* getTexture();

	void setDimensions(int width, int height);
	void setPosition(PPoint* point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	int getOrder(){ return _order; }

	virtual void click(){};

};
#endif // CELL_H__