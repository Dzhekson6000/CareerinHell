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

	int xCell = floor( (yClick + xClick / 2)/50 );
	int yCell = floor(  (yClick - xClick / 2)/50 );

	if(_interfaceGame->isSelectCharacter())
	{
		_interfaceGame->getSelectCharacter()->setPosition(new PPoint(xCell * 50, yCell *50) );
	}

	std::vector<Cell*>* cells = _level->getCells();

	for(time_t i = 0; i < cells->size(); i++)
	{
		
		PPoint * point =  cells->at(cells->size() -1 -i)->getPosition();
		if( (int)floor(point->getXOriginal()/50) == xCell && (int)floor(point->getYOriginal()/50) == yCell)
		{
			cells->at(cells->size() -1 -i)->click();
		}
	}

}