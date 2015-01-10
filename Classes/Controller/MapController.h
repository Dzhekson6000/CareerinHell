#ifndef MAPCONTROLLER_H__
#define MAPCONTROLLER_H__

#include "cocos2d.h"
#include "InterfaceGame.h"
#include "Level.h"
#include "Tools/Scroller.h"
#include "Tools/PPoint.h"

USING_NS_CC;

class MapController
{
private:
	Level* _level;
	Scroller* _scroll;
	InterfaceGame* _interfaceGame;
public:
	MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame);
	void click(Touch* touch);
};
#endif // MAPCONTROLLER_H__