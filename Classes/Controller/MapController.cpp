#include "MapController.h"

MapController::MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame)
{
	_level = level;
	_scroll = scroll;
	_interfaceGame = interfaceGame;
}

void MapController::click(Touch* touch)
{
	if(_interfaceGame->isInterfaceClick(touch))return;

	float xClick = touch->getLocation().x - _scroll->getPositionX();
	float yClick = touch->getLocation().y - _scroll->getPositionY();

	int xCell = (yClick + xClick / 2)/50;
	int yCell = (yClick - xClick / 2)/50;


	if(_interfaceGame->isSelectCharacter())
	{
		_interfaceGame->getSelectCharacter()->setPosition(new PPoint(xCell * 50, yCell *50) );
	}
}