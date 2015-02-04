#ifndef MAPCONTROLLER_H__
#define MAPCONTROLLER_H__

#include "cocos2d.h"
#include "InterfaceGame.h"
#include "Level.h"
#include "Tools/Scroller.h"
#include "Tools/PPoint.h"
#include "Tools/HighlightingCells.h"

USING_NS_CC;

class MapController
{
private:
	Level* _level;
	Scroller* _scroll;
	InterfaceGame* _interfaceGame;
	HighlightingCells* _highlightingCells;
	int** _passageWays;
	void initPassageWays();
	void clearPassageWays();
	void transition();
public:
	MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame);
	void update(float dt);
	void click(Touch* touch);
	int** getPassageWays();
	CC_SYNTHESIZE_READONLY(int, _xMax, Width);
	CC_SYNTHESIZE_READONLY(int, _yMax, Height);
	CC_SYNTHESIZE_READONLY(int, _xMin, WidthMin);
	CC_SYNTHESIZE_READONLY(int, _yMin, HeightMin);
};
#endif // MAPCONTROLLER_H__