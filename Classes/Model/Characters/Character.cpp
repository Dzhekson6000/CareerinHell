#include "Character.h"

Character::Character(int id, PPoint* point)
{
	_id = id;
	_width = 0;
	_height = 0;
	_inversionX = false;
	_inversionY = false;
	this->_sprite = Sprite::create(PATH_CHARACTERS "boat.png");
	this->setSize(100,100);
	setPosition(point);
}


PPoint* Character::getPosition()
{
	return _point;
}

void Character::createSprite(std::string textureName)
{
	_sprite = Sprite::create(textureName + ".png");
	setPosition(_point);
	_sprite->setScaleX(getInverse(_inversionX));
	_sprite->setScaleY(getInverse(_inversionY));
	addChild(_sprite);
}

void Character::setPosition(PPoint* point)
{
	_point = point;
	float x = point->getX() - _width;
	if(_inversionX)x = point->getX() + _width;
	this->_sprite->setPosition(x, point->getY() + _height );
	this->_sprite->setLocalZOrder(-(point->getXOriginal() + point->getYOriginal()) );
}

void Character::setSize(int width, int height)
{
	_width = width;
	_height = height;
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

void Character::update()
{

}

