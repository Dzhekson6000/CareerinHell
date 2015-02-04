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
};
#endif // TILECELL_H__