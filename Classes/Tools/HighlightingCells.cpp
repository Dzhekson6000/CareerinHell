#include "HighlightingCells.h"

HighlightingCells::HighlightingCells(Layer* parentLayer, Level* level)
{
	_parentLayer = parentLayer;
	_level = level;
	_order = -1;
	_sprites = new std::vector<Sprite*>;
	updateGrid();
}

void HighlightingCells::update( PPoint* point, int length )
{
	clearSprite();
	_point = point;
	_length = length;
	setStatus(true);
}

void HighlightingCells::clearSprite()
{
	for(time_t i = 0; i < _sprites->size(); i++)
	{
		_parentLayer->removeChild(_sprites->at(i));
	}
	_sprites->clear();
}

void HighlightingCells::setStatus( bool status )
{
	_status = status;
	if(status)
	{
		updateGrid();
		createHighlightingCells();
	} else {
		clearSprite();
	}
}

void HighlightingCells::createHighlightingCells()
{
	const int BLANK = -2;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int d, x, y, k;
	bool stop;

	d = 0;
	_grid[_point->getXCell()-_level->getXMinCell()][_point->getYCell()-_level->getYMinCell()] = 0;
	do {
		stop = true;
		for ( x = 0; x <= _level->getXMaxCell() - _level->getXMinCell(); ++x )
			for ( y = 0; y <= _level->getYMaxCell() - _level->getYMinCell(); ++y )
				if ( _grid[x][y] == d )
				{
					for ( k = 0; k < 4; ++k )
					{
						int iy=y + dy[k], ix = x + dx[k];
						if ( iy >= 0 && iy < _level->getYMaxCell() - _level->getYMinCell() && ix >= 0 && ix < _level->getXMaxCell() - _level->getXMinCell() &&
							_grid[ix][iy] == BLANK )
						{
							stop = false;
							_grid[ix][iy] = d + 1;
						}
						addSprite(new PPoint(x+_level->getXMinCell(),y+_level->getYMinCell()));
					}
				}
				d++;
	} while ( !stop && d <= _length);
}

void HighlightingCells::addSprite( PPoint* point )
{
	Sprite* sprite = Sprite::create(PATH_EXTRA "canPass.png");
	sprite->setPosition(point->getX(), point->getY() + sprite->getContentSize().height/2);
	sprite->setLocalZOrder(-(point->getXOriginal() + point->getYOriginal()) + _order * 200 );
	_parentLayer->addChild(sprite);
	_sprites->push_back(sprite);
}

void HighlightingCells::updateGrid()
{
	const int WALL   = -1;
	const int BLANK  = -2;
	int** passageWays = _level->getPassageWays();

	_grid = new int*[_level->getXMaxCell() - _level->getXMinCell()+1];
	for(int i=0; i<=_level->getXMaxCell() - _level->getXMinCell(); i++)
	{
		_grid[i] = new int [_level->getYMaxCell() - _level->getYMinCell()+1];
		for(int j=0; j<=_level->getYMaxCell() - _level->getYMinCell(); j++)
		{
			if(passageWays[i][j] == 0)
			{
				_grid[i][j] = BLANK;
			}
			else
			{
				_grid[i][j] = WALL;
			}
		}
	}
}
