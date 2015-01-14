#include "TileCell.h"

TileCell::TileCell()
{
	_sizeX = 1;
	_sizeY = 1;
	_order = 0;
	_passage = 255;
	_point = new PPoint(0,0);
	_cells = new std::vector <Cell*>;
}

void TileCell::addCell(std::string textureName, bool inversionX, bool inversionY)
{
	addCell(new PPoint(0, 0), textureName, inversionX, inversionY);
}

void TileCell::addCell(PPoint* point, std::string textureName, bool inversionX, bool inversionY)
{
	Cell* cell = new Cell(point, _point, textureName, inversionX, inversionY);
	cell->setOrder(_order);
	cell->setPassage(_passage);
	_cells->push_back(cell);
}


void TileCell::setPosition(PPoint* point){
	_point = point;

	for(time_t i = 0; i < _cells->size(); i++)
	{
		_cells->at(i)->setPositionTile(_point);
	}
}

void TileCell::setPassage(int passage)
{
	_passage = passage;
	for(time_t i = 0; i < _cells->size(); i++)
	{
		_cells->at(i)->setPassage(passage);
	}
}

void TileCell::setOrder(int order)
{
	_order = order;
	for(time_t i = 0; i < _cells->size(); i++)
	{
		_cells->at(i)->setOrder(_order);
	}
}

PPoint* TileCell::getPosition()
{
	return _point;
}

std::vector <Cell*>* TileCell::getCells()
{
	return _cells;
}

/*Cell::Cell(PPoint* point)
{
	_width = 0;
	_height = 0;
	_xCenter = 0;
	_yCenter = 0;
	_inversionX = false;
	_inversionY = false;
	this->_sprite = Sprite::create(defaultImage);
	this->setSize(100,100);
	setPosition(point);
}


PPoint* Cell::getPosition()
{
	return _point;
}

void Cell::createSprite(std::string textureName)
{
	_sprite = Sprite::create(textureName + ".png");
	setPosition(_point);
	_sprite->setScaleX(getInverse(_inversionX));
	_sprite->setScaleY(getInverse(_inversionY));
}

Sprite* Cell::getTexture()
{
	return _sprite;
}

void Cell::setPosition(PPoint* point)
{
	_point = point;
	this->_sprite->setPosition(point->getX() - _xCenter, point->getY() + _yCenter);
}

void Cell::setSize(int width, int height)
{
	_width = width;
	_height = height;
	_yCenter = (_height/2);
}

void Cell::setCenter(int xCenter, int yCenter)
{
	_xCenter = xCenter;
	_yCenter = yCenter;
}

void Cell::setInversionX(bool inversion)
{
	_inversionX = inversion;
	_sprite->setScaleX(getInverse(inversion));
}

void Cell::setInversionY(bool inversion)
{
	_inversionY = inversion;
	_sprite->setScaleY(getInverse(inversion));
}

int Cell::getInverse(bool inversion)
{
	return inversion ? -1: 1;
}*/
