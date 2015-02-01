#include "MapController.h"
#include "Tools/Pathfinding.h"

#define DNT_WALK 255

MapController::MapController(Level* level, Scroller* scroll, InterfaceGame* interfaceGame)
{
	_level = level;
	_scroll = scroll;
	_interfaceGame = interfaceGame;
	_map = new PMap();
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
		//_interfaceGame->getSelectCharacter()->setPosition(new PPoint(xCell * 50, yCell *50) );
		_interfaceGame->getSelectCharacter()->goMove(xCell, yCell);
		CCLOG("xCell=%i yCell=%i", xCell, yCell);
		CCLOG("cell=%i", _map->_passageWays[xCell][yCell]);
		PPoint* point = new PPoint();
		point->setXCell(xCell);
		point->setYCell(yCell);
		Pathfinder::find(point, _interfaceGame->getSelectCharacter(), _map);
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
			int passage = cells->at(cells->size() -1 -i)->getPassage();
			if( (_map->_passageWays[x][y] == -1) || (passage > _map->_passageWays[x][y]) )
			{
				_map->_passageWays[x][y] = passage;
			}
			
		}
	}

	for(int i=0; i<_map->getWidth(); i++)
	{
		for(int j=0; j<_map->getHeight(); j++)
		{
			if(_map->_passageWays[i][j] == -1) {
				_map->_passageWays[i][j] = DNT_WALK;
			} 
		}
	}

	return _map->_passageWays;
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
			if(_map->getWidth() < x) _map->setWidth(x);
			if(_map->getHeight() < y) _map->setHeight(y);
		}
	}

	_map->_passageWays = new int*[_map->getWidth()+1];
	for(int i=0; i<_map->getWidth()+1; i++)
	{
		_map->_passageWays[i] = new int [_map->getHeight()+1];
		for(int j=0; j<_map->getHeight()+1; j++)
		{
			_map->_passageWays[i][j] = -1;
		}
	}
	getPassageWays();
}
void MapController::clearPassageWays()
{
	for(int i=0; i<_map->getWidth(); i++)
	{
		for(int j=0; j<_map->getHeight(); j++)
		{
			_map->_passageWays[i][j] = -1;
		}
	}
}

void MapController::update( float dt )
{
	std::vector<Character*>* characters = _level->getCharacters();
	for(time_t i = 0; i < characters->size(); i++)
	{
		characters->at(characters->size() -1 -i   )->update();
	}
}
