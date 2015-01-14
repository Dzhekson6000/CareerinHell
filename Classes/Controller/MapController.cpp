#include "MapController.h"

#define DNT_WALK 255

MapController::MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame)
{
	_level = level;
	_scroll = scroll;
	_interfaceGame = interfaceGame;
	initPassageWays();
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

	std::vector<TileCell*>* tileCells = _level->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t i = 0; i < cells->size(); i++)
		{
			if( cells->at(i)->getCellX() == xCell && cells->at(i)->getCellY() == yCell)
			{
				tileCells->at(i)->click();
			}
		}
	}
}

int** MapController::getPassageWays()
{
	clearPassageWays();

	std::vector<TileCell*>* tileCells = _level->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t i = 0; i < cells->size(); i++)
		{
			int x = cells->at(i)->getCellX();
			int y = cells->at(i)->getCellY();
			_passageWays[x][y] = cells->at(cells->size() -1 -i)->getPassage();
		}
	}

	for(int i=0; i<_xMax; i++)
	{
		for(int j=0; j<_yMax; j++)
		{
			if(_passageWays[i][j] == -1) _passageWays[i][j] = DNT_WALK;
		}
	}

	return _passageWays;
}

void MapController::initPassageWays()
{
	std::vector<TileCell*>* tileCells = _level->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t i = 0; i < cells->size(); i++)
		{
			int x = cells->at(i)->getCellX();
			int y = cells->at(i)->getCellY();
			if(_xMax < x) _xMax = x;
			if(_yMax < y) _yMax = y;
		}
	}

	_passageWays = new int*[_xMax];
	for(int i=0; i<_xMax; i++)
	{
		_passageWays[i] = new int [_yMax];
		for(int j=0; j<_yMax; j++)
		{
			_passageWays[i][j] = -1;
		}
	}
}
void MapController::clearPassageWays()
{
	for(int i=0; i<_xMax; i++)
	{
		for(int j=0; j<_yMax; j++)
		{
			_passageWays[i][j] = -1;
		}
	}
}