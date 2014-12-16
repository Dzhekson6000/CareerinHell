#include "Cell.h"

Cell::Cell(PPoint* point)
{
	_width = 0;
	_height = 0;
	_inversionX = false;
	_inversionY = false;
	this->_sprite = Sprite::create(defaultImage);
	this->setDimensions(100,100);
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
	updateInversion();
}

Sprite* Cell::getTexture()
{
	return _sprite;
}

void Cell::setPosition(PPoint* point)
{
	_point = point;
	this->_sprite->setPosition(point->getX(), point->getY() + (_height/2) );
}

void Cell::setDimensions(int width, int height)
{
	_width = width;
	_height = height;
}

void Cell::setInversionX(bool inversion)
{
	_inversionX = inversion;
	updateInversion();
}

void Cell::setInversionY(bool inversion)
{
	_inversionY = inversion;
	updateInversion();
}

void Cell::updateInversion()
{
	if(_inversionX) _sprite->setScaleX(1); else _sprite->setScaleX(-1);
	if(_inversionY) _sprite->setScaleY(-1); else _sprite->setScaleY(1);
}