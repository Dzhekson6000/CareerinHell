#ifndef CELL_H__
#define CELL_H__
#include "cocos2d.h"
#include "Tools/PPoint.h"

USING_NS_CC;

class Cell
{
private:
	Sprite* _texture;
	PPoint _point;
	PPoint* _pointTile;
	bool _inversionX;
	bool _inversionY;
	int _passage;
	int _order;

	int getInverse(bool inversion);
protected:
public:
	Cell(PPoint point, PPoint* pointTile, std::string textureName, bool inversionX, bool inversionY);
	Sprite* getTexture();
	void updateOrder();

	void setPosition(PPoint point);
	void setPositionTile(PPoint* point);
	void setPassage(int passage){ _passage = passage; }
	void setOrder(int order);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	int getPassage(){ return _passage; }
	int getOrder(){ return _order; }
	int getCellX();
	int getCellY();
};
#endif // CELL_H__