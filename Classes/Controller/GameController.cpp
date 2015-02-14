#include "GameController.h"

#define DNT_WALK 255

GameController::GameController(Scroller* scroll, InterfaceGame* interfaceGame)
{
	_level = new Level;
	_scroll = scroll;

	_player = new Player;
	_player->setCharacters(new std::vector<Character*>);

	_interfaceGame = interfaceGame;
	_interfaceGame->addEventOnHiringUnit(INTERFACE_CALLBACK_1(GameController::eventUnit, this) );
	_interfaceGame->addEventOnWarpPortal(INTERFACE_CALLBACK_1(GameController::eventWarpPortal, this) );

	nextLevel("hell.xml", true);
	_highlightingCells = new HighlightingCells(_scroll, _level);
}

void GameController::click(Touch* touch)
{
	if(_interfaceGame->isSelectCharacter())
	{
		_highlightingCells->update(_interfaceGame->getSelectCharacter()->getPPosition(), _interfaceGame->getSelectCharacter()->getActionPoints());
	}else{
		_highlightingCells->setStatus(false);
	}

	if(_interfaceGame->isInterfaceClick(touch))return;
	if(_interfaceGame->isButEndCoClick(touch))
	{
		transition();
		return;
	}

	float xClick = touch->getLocation().x - _scroll->getPositionX();
	float yClick = touch->getLocation().y - _scroll->getPositionY();

	int xCell = floor( (yClick + xClick / 2)/50 );
	int yCell = floor(  (yClick - xClick / 2)/50 );

	if(_interfaceGame->isSelectCharacter())
	{
		_interfaceGame->getSelectCharacter()->goMove(new PPoint(xCell, yCell), _level);
	}

	std::vector<TileCell*>* tileCells = _level->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t j = 0; j < cells->size(); j++)
		{
			if( cells->at(j)->getCellX() == xCell && cells->at(j)->getCellY() == yCell)
			{
				tileCells->at(i)->click(_interfaceGame);
			}
		}
	}
}

void GameController::transition()
{
	std::vector<Character*>* character = _level->getCharacters();
	for(time_t i = 0; i < character->size(); i++)
	{
		character->at(i)->transition();
	}
}

int** GameController::getPassageWays()
{
	clearPassageWays();

	std::vector<TileCell*>* tileCells = _level->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t i = 0; i < cells->size(); i++)
		{
			int x = cells->at(i)->getCellX()-_xMin;
			int y = cells->at(i)->getCellY()-_yMin;
			int passage = cells->at(cells->size() -1 -i)->getPassage();
			if( (_passageWays[x][y] == -1) || (passage > _passageWays[x][y]) )
				_passageWays[x][y] = passage;
			
		}
	}

	for(int i=0; i<_xMax-_xMin+1; i++)
	{
		for(int j=0; j<_yMax-_yMin+1; j++)
		{
			if(_passageWays[i][j] == -1) _passageWays[i][j] = DNT_WALK;
		}
	}

	return _passageWays;
}

void GameController::initPassageWays()
{
	_xMin = 0;_yMin = 0;_xMax = 0;_yMax = 0;
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
			if(_xMin > x) _xMin = x;
			if(_yMin > y) _yMin = y;
		}
	}

	_passageWays = new int*[_xMax-_xMin+1];
	for(int i=0; i<_xMax-_xMin+1; i++)
	{
		_passageWays[i] = new int [_yMax - _yMin+1];
		for(int j=0; j<_yMax-_yMin+1; j++)
		{
			_passageWays[i][j] = -1;
		}
	}
	getPassageWays();
}

void GameController::clearPassageWays()
{
	for(int i=0; i<_xMax-_xMin+1; i++)
	{
		for(int j=0; j<_yMax-_yMin+1; j++)
		{
			_passageWays[i][j] = -1;
		}
	}
}

void GameController::update( float dt )
{
	std::vector<Character*>* characters = _level->getCharacters();
	for(time_t i = 0; i < characters->size(); i++)
	{
		characters->at(characters->size() -1 -i   )->update();
	}

	if(_interfaceGame->isSelectCharacter() && (
		_interfaceGame->getSelectCharacter()->getPPosition()->getXCell() == _interfaceGame->getSelectCharacter()->getActionXCell() &&
		_interfaceGame->getSelectCharacter()->getPPosition()->getYCell() == _interfaceGame->getSelectCharacter()->getActionYCell()
		) )
	{
		_highlightingCells->update(_interfaceGame->getSelectCharacter()->getPPosition(), _interfaceGame->getSelectCharacter()->getActionPoints() );
	}
}

void GameController::nextLevel( std::string level, bool isHell )
{
	clearLevel();
	ReadLevel rl = ReadLevel();
	rl.readFile(PATH_MAP + level);
	_level = rl.getLevel();
	std::vector<Character*>* characters = rl.getLevel()->getCharacters();
	if(!isHell)
	{
		std::vector<Character*>* playerCharacters = _player->getCharacters();
		for(time_t i = 0; i < playerCharacters->size(); i++)
		{
			playerCharacters->at(i)->setPPosition(new PPoint(_level->getXPortalCell(), _level->getYPortalCell()) );
			characters->push_back(playerCharacters->at(i));
		}
	}
	std::vector<TileCell*>* tileCells = rl.getLevel()->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t j = 0; j < cells->size(); j++)
		{
			_scroll->addChild(cells->at(cells->size() -1 -j)->getTexture());
		}
	}

	for(time_t i = 0; i < characters->size(); i++)
	{
		_interfaceGame->addCharacter(characters->at(characters->size() -1 -i   ));
		_scroll->addChild(characters->at(characters->size() -1 -i   ));
	}

	std::vector<Character*>* charactersAI = rl.getLevel()->getCharactersAI();
	for(time_t i = 0; i < charactersAI->size(); i++)
	{
		_scroll->addChild(charactersAI->at(charactersAI->size() -1 -i   ));
	}

	initPassageWays();
	_level->setPassageWays(getPassageWays());
	_level->setXMaxCell(_xMax);
	_level->setYMaxCell(_yMax);
	_level->setXMinCell(_xMin);
	_level->setYMinCell(_yMin);
}

void GameController::clearLevel()
{
	_scroll->removeAllChildren();
}

void GameController::eventUnit( int id )
{
	std::string tip = "";
	if(id == 1) tip = "boat";
	std::vector<Character*>* playerCharacter = _player->getCharacters();
	playerCharacter->push_back(new Boat(1, new PPoint(0, 0), tip, true ));
}

void GameController::eventWarpPortal( std::string nameLevel )
{
	nextLevel(nameLevel);
}
