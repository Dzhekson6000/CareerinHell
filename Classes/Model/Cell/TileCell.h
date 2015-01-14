#ifndef TILECELL_H__
#define TILECELL_H__
#include "cocos2d.h"
#include "Tools/PPoint.h"
#include "Common/common.h"
#include "Cell.h"

USING_NS_CC;

class TileCell
{
private:
	PPoint* _point;
	int _sizeX;
	int _sizeY;
	int _order;
	int _passage;
	std::vector <Cell*>* _cells;
protected:
	TileCell();
	void setSize(int x, int y);
	void addCell(std::string textureName, bool inversionX, bool inversionY);
	void addCell(PPoint* point, std::string textureName, bool inversionX, bool inversionY);
public:
	void setPosition(PPoint* point);
	void setPassage(int passage);
	void setOrder(int order);

	PPoint* getPosition();
	std::vector <Cell*>* getCells();
	int getPassage(){ return _passage; }

	virtual void click(){};

/*private:
	int _width;
	int _height;
	int _xCenter;
	int _yCenter;
	bool _inversionX;
	bool _inversionY;
	int getInverse(bool inversion);
protected:
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
	
	int getPassage(){ return _passage; }
	int getOrder(){ return _order; }

	virtual void click(){};*/

};
#endif // TILECELL_H__