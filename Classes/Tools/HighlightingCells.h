#ifndef HIGHLIGHTING_CELLS_H__
#define HIGHLIGHTING_CELLS_H__

#include "cocos2d.h"
#include "PPoint.h"
#include "Common/common.h"
#include "Controller/Level.h"

USING_NS_CC;

class HighlightingCells
{
private:
	std::vector<Sprite*> _sprites;
	PPoint _point;
	int _length;
	Layer* _parentLayer;
	Level* _level;
	bool _status;
	int _order;
	void createHighlightingCells();
	void addSprite(PPoint point);
	int** _grid;
	void updateGrid();
	void clearSprite();
public:
	HighlightingCells(Layer* parentLayer, Level* level);
	void create(PPoint point, int length);
	void setStatus(bool status);
	void update(PPoint point, int length);

	CC_SYNTHESIZE(int, _actionXCell, ActionXCell);
	CC_SYNTHESIZE(int, _actionYCell, ActionYCell);
};

#endif // HIGHLIGHTING_CELLS_H__