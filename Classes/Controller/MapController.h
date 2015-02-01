#ifndef MAPCONTROLLER_H__
#define MAPCONTROLLER_H__

#include "cocos2d.h"
#include "InterfaceGame.h"
#include "Level.h"
#include "Tools/Scroller.h"
#include "Tools/PPoint.h"
#include "Model/PMap.h"

USING_NS_CC;

class MapController
{
private:
	Level* _level;
	Scroller* _scroll;
	InterfaceGame* _interfaceGame;
	void initPassageWays();
	void clearPassageWays();
public:
	MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame);
	void update(float dt);
	void click(Touch* touch);
	int** getPassageWays();
	CC_SYNTHESIZE(PMap*, _map, Map);
};
#endif // MAPCONTROLLER_H__