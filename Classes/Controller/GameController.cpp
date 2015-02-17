#include "GameController.h"

#define DNT_WALK 255

GameController::GameController(Scroller* scroll, InterfaceGame* interfaceGame, Settings* settings)
{
	_level = new Level;
	_scroll = scroll;
	_settings = settings;

	_player = new Player;
	_player->setNCharacter(0);

	_interfaceGame = interfaceGame;
	_interfaceGame->addEventOnHiringUnit(INTERFACE_CALLBACK_1(GameController::eventUnit, this) );
	_interfaceGame->addEventOnWarpPortal(INTERFACE_CALLBACK_1(GameController::eventWarpPortal, this) );
	_interfaceGame->addEventOnTransition(INTERFACE_CALLBACK_0(GameController::transition, this) );
	_interfaceGame->setQuestions(_level->getQuestions());

	nextLevel("hell.xml", true);
	_highlightingCells = new HighlightingCells(_scroll, _level);
	
}

void GameController::click(Touch* touch)
{
	if(_interfaceGame->isSelectCharacter())
	{
		_highlightingCells->setActionXCell(_interfaceGame->getSelectCharacter()->getActionXCell());
		_highlightingCells->setActionYCell(_interfaceGame->getSelectCharacter()->getActionYCell());
		_highlightingCells->update(*(_interfaceGame->getSelectCharacter()->getPPosition()), _interfaceGame->getSelectCharacter()->getActionPoints());
	}else{
		_highlightingCells->setStatus(false);
	}

	if(_interfaceGame->isInterfaceClick(touch))return;

	float xClick = touch->getLocation().x - _scroll->getPositionX();
	float yClick = touch->getLocation().y - _scroll->getPositionY();

	int xCell = floor( (yClick + xClick / 2)/50 );
	int yCell = floor(  (yClick - xClick / 2)/50 );

	if(_interfaceGame->isSelectCharacter())
	{
		_interfaceGame->getSelectCharacter()->goMove(PPoint(xCell, yCell));
	}

	for(auto tileCell: _level->getTileCells())
	{
		for(auto cell: *(tileCell->getCells()))
		{
			if( cell.getCellX() == xCell && cell.getCellY() == yCell)
			{
				tileCell->click(_interfaceGame);
			}
		}
	}
}

void GameController::transition()
{
	for(auto character: _level->getCharacters())
	{
		character->transition();
	}
}

int** GameController::getPassageWays()
{
	clearPassageWays();

	for(auto tileCell: _level->getTileCells())
	{
		for(auto cell: *(tileCell->getCells()))
		{
			int x = cell.getCellX()-_xMin;
			int y = cell.getCellY()-_yMin;
			int passage = cell.getPassage();
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

	for(auto tileCell: _level->getTileCells())
	{
		for(auto cell: *(tileCell->getCells()))
		{
			int x = cell.getCellX();
			int y = cell.getCellY();
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
	for(auto characters: _level->getCharacters())
	{
		characters->update();
	}

	if(_interfaceGame->isSelectCharacter() && (
		_highlightingCells->getActionXCell() != _interfaceGame->getSelectCharacter()->getActionXCell() ||
		_highlightingCells->getActionYCell() != _interfaceGame->getSelectCharacter()->getActionYCell()
		) )
	{
		_highlightingCells->setActionXCell(_interfaceGame->getSelectCharacter()->getActionXCell());
		_highlightingCells->setActionYCell(_interfaceGame->getSelectCharacter()->getActionYCell());
		_highlightingCells->update(PPoint(_highlightingCells->getActionXCell(), _highlightingCells->getActionYCell()), _interfaceGame->getSelectCharacter()->getActionPoints() );
	}
}

void GameController::nextLevel( std::string level, bool isHell )
{
	clearLevel();
	ReadLevel rl = ReadLevel(_settings,PATH_MAP + level);
	*_level = *rl.getLevel();

	if(!isHell)
	{
		for(auto character: _player->_characters)
		{
			character->setPPosition(PPoint(_level->getXPortalCell(), _level->getYPortalCell()) );
		}
		_level->setCharacters(_player->_characters);
	}
	for(auto tileCell: _level->getTileCells())
	{
		for(auto cell: *(tileCell->getCells()) )
		{
			_scroll->addChild(cell.getTexture());
		}
	}

	for(auto character:_level->getCharacters())
	{
		_interfaceGame->addCharacter(character);
		_scroll->addChild(character);
	}

	for(auto character:_level->getCharactersAI())
	{
		_scroll->addChild(character);
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
	_level->release();
	_scroll->removeAllChildren();
	_interfaceGame->clearCharacter();
}

void GameController::eventUnit( int id )
{
	std::string tip = "";
	if(id == 1) tip = "boat";
	_player->_characters.push_back(new Boat(_player->augmentN(), _level, PPoint(0, 0), tip, false));

}

void GameController::eventWarpPortal( std::string nameLevel )
{
	nextLevel(nameLevel);
}
