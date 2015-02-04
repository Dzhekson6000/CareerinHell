#include "Character.h"

Character::Character(int id, PPoint* point, std::string textureName)
{
	_id = id;
	_actionPoints = 10;
	_actionPointsMax = 10;
	_actionXCell = point->getXCell();
	_actionYCell = point->getYCell();
	_hitPoints = 100;
	_hitPointsMax = 100;
	_attackPoints = 10;
	_inversionX = false;
	_inversionY = false;
	_path = new std::vector<PPoint*>;
	this->_sprite = Sprite::create(textureName + ".png");
	setPPosition(point);
	_sprite->setScaleX(getInverse(_inversionX));
	_sprite->setScaleY(getInverse(_inversionY));
	addChild(_sprite);
}


PPoint* Character::getPPosition()
{
	return _point;
}


void Character::setPPosition(PPoint* point)
{
	_point = point;
	this->setPosition(point->getX(), point->getY() + _sprite->getContentSize().height/2 );
	this->setLocalZOrder(-(point->getXOriginal() + point->getYOriginal()) );
}

void Character::setInversionX(bool inversion)
{
	_inversionX = inversion;
	_sprite->setScaleX(getInverse(inversion));
}

void Character::setInversionY(bool inversion)
{
	_inversionY = inversion;
	_sprite->setScaleY(getInverse(inversion));
}

int Character::getInverse(bool inversion) {
	return inversion ? -1: 1;
}

void Character::transition()
{
	_actionPoints = _actionPointsMax;
}

void Character::update()
{
	if(_actionPoints == 0)return;

	int x = _point->getXOriginal();
	int y = _point->getYOriginal();
	PPoint* targetPoint = NULL;
	if(_path->size() != 0)
	{
		targetPoint = new PPoint(_path->at(0)->getXCell(), _path->at(0)->getYCell());
		if( (int)(_path->at(0)->getXOriginal()) == x && (int)(_path->at(0)->getYOriginal()) == y)
		{
			_actionPoints--;
			_actionXCell = _point->getXCell();
			_actionYCell = _point->getYCell();
			_path->erase(_path->begin());
		}
	}
	if(targetPoint == NULL)return;
	if(_point->getXOriginal() != targetPoint->getXOriginal())
	{
		if(_point->getXOriginal() > targetPoint->getXOriginal())
		{
			x--;
		}
		if(_point->getXOriginal() < targetPoint->getXOriginal())
		{
			x++;
		}
	}
	if(_point->getYOriginal() != targetPoint->getYOriginal())
	{
		if(_point->getYOriginal() > targetPoint->getYOriginal())
		{
			y--;
		}
		if(_point->getYOriginal() < targetPoint->getYOriginal())
		{
			y++;
		}
	}
	setPPosition(new PPoint((float)x,(float)y) );
}

void Character::goMove(PPoint* point, Level* level)
{
	if(point->getXCell() < level->getXMinCell() || point->getYCell() < level->getYMinCell() ||
		point->getXCell() > level->getXMaxCell() || point->getYCell() > level->getYMaxCell()) return;
	clock_t time = clock();
	findPath(point, level);
	time = clock() - time;
	CCLOG("----END----");
	CCLOG("time = %f", (double)time/CLOCKS_PER_SEC);
}

void Character::findPath(PPoint* pointTarget, Level* level)
{
	clearPath();

	const int WALL   = -1;
	const int BLANK  = -2;
	int len;
	int** passageWays = level->getPassageWays();
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int d, x, y, k;
	bool stop;

	int** grid = new int*[level->getXMaxCell() - level->getXMinCell()+1];
	for(int i=0; i<=level->getXMaxCell() - level->getXMinCell(); i++)
	{
		grid[i] = new int [level->getYMaxCell() - level->getYMinCell()+1];
		for(int j=0; j<=level->getYMaxCell() - level->getYMinCell(); j++)
		{
			if(passageWays[i][j] == 0)
			{
				grid[i][j] = BLANK;
			}
			else
			{
				grid[i][j] = WALL;
			}
		}
	}

	if (grid[_point->getXCell()-level->getXMinCell()][_point->getYCell()-level->getYMinCell()] == WALL ||
		grid[pointTarget->getXCell()-level->getXMinCell()][pointTarget->getYCell()-level->getYMinCell()] == WALL)
	{
		CCLOG("Failed WALL");
		return;
	}

	d = 0;
	grid[_point->getXCell()-level->getXMinCell()][_point->getYCell()-level->getYMinCell()] = 0;
	do {
		stop = true;
		for ( x = 0; x <= level->getXMaxCell() - level->getXMinCell(); ++x )
			for ( y = 0; y <= level->getYMaxCell() - level->getYMinCell(); ++y )
				if ( grid[x][y] == d )
				{
					for ( k = 0; k < 4; ++k )
					{
						int iy=y + dy[k], ix = x + dx[k];
						if ( iy >= 0 && iy < level->getYMaxCell() - level->getYMinCell() && ix >= 0 && ix < level->getXMaxCell() - level->getXMinCell() &&
							grid[ix][iy] == BLANK )
						{
							stop = false;
							grid[ix][iy] = d + 1;
						}
					}
				}
				d++;
	} while ( !stop && grid[pointTarget->getXCell()-level->getXMinCell()][pointTarget->getYCell()-level->getYMinCell()] == BLANK );

	if (grid[pointTarget->getXCell()-level->getXMinCell()][pointTarget->getYCell()-level->getYMinCell()] == BLANK)
	{
		CCLOG("Failed find path");
		return;
	}

	len = grid[pointTarget->getXCell()-level->getXMinCell()][pointTarget->getYCell()-level->getYMinCell()];
	x = pointTarget->getXCell()-level->getXMinCell();
	y = pointTarget->getYCell()-level->getYMinCell();
	d = len;

	int* px = new int[len];
	int* py = new int[len];

	while ( d > 0 )
	{
		px[d-1] = x+level->getXMinCell();
		py[d-1] = y+level->getYMinCell();
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy=y + dy[k], ix = x + dx[k];
			if ( iy >= 0 && iy < level->getYMaxCell() - level->getYMinCell() && ix >= 0 && ix < level->getXMaxCell() - level->getXMinCell() &&
				grid[ix][iy] == d)
			{
				x = x + dx[k];
				y = y + dy[k];
				break;
			}
		}
	}

	for(time_t i = 0; i < len; i++)
	{
		_path->push_back(new PPoint(px[i], py[i]));
	}

}

void Character::clearPath()
{
	_path->clear();
}