#ifndef MAPCONTROLLER_H__
#define MAPCONTROLLER_H__

#include "cocos2d.h"
#include "InterfaceGame.h"
#include "Level.h"
#include "Tools/Scroller.h"
#include "Tools/PPoint.h"
#include "Tools/HighlightingCells.h"
#include "Controller/ReadLevel.h"
#include "Player.h"

USING_NS_CC;

class GameController
{
private:
	Level* _level;
	Player* _player;
	Scroller* _scroll;
	Settings* _settings;
	InterfaceGame* _interfaceGame;
	HighlightingCells* _highlightingCells;
	int** _passageWays;
	void initPassageWays();
	void clearPassageWays();
	void transition();
public:
	GameController(Scroller* scroll, InterfaceGame* interfaceGame, Settings* settings);
	void update(float dt);
	void click(Touch* touch);
	int** getPassageWays();
	CC_SYNTHESIZE_READONLY(int, _xMax, Width);
	CC_SYNTHESIZE_READONLY(int, _yMax, Height);
	CC_SYNTHESIZE_READONLY(int, _xMin, WidthMin);
	CC_SYNTHESIZE_READONLY(int, _yMin, HeightMin);
	void nextLevel(std::string level, bool isHell = false);
	void clearLevel();

	void eventUnit(int id);
	void eventWarpPortal(std::string nameLevel);
};
#endif // MAPCONTROLLER_H__