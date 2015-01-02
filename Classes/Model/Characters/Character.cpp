#include "Character.h"

Character::Character(PPoint* point)
{
	_width = 0;
	_height = 0;
	_inversionX = false;
	_inversionY = false;
	this->_sprite = Sprite::create("img/characters/boat.png");
	this->setCenter(100,100);
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
	updateInversion();
}

Sprite* Character::getTexture()
{
	return _sprite;
}

void Character::setPosition(PPoint* point)
{
	_point = point;
	float x = point->getX() - _width;
	if(_inversionX)x = point->getX() + _width;
	this->_sprite->setPosition(x, point->getY() + _height );
}

void Character::setCenter(int width, int height)
{
	_width = width;
	_height = height;
}

void Character::setInversionX(bool inversion)
{
	_inversionX = inversion;
	updateInversion();
}

void Character::setInversionY(bool inversion)
{
	_inversionY = inversion;
	updateInversion();
}

void Character::updateInversion()
{
	if(_inversionX) _sprite->setScaleX(-1); else _sprite->setScaleX(1);
	if(_inversionY) _sprite->setScaleY(-1); else _sprite->setScaleY(1);
}

void Character::update()
{

}