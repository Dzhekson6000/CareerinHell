#include "Cell.h"

Cell::Cell(PPoint* point)
{
	_order = 0;
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
}
