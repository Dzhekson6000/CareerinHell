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
	_targetMove = point;
	setPosition(point);
}


PPoint* Character::getPPosition()
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
	int x = _point->getXOriginal();
	int y = _point->getYOriginal();
	if(_point->getXOriginal() != _targetMove->getXOriginal())
	{
		if(_point->getXOriginal() > _targetMove->getXOriginal())
		{
			x--;
		}
		if(_point->getXOriginal() < _targetMove->getXOriginal())
		{
			x++;
		}
	}
	if(_point->getYOriginal() != _targetMove->getYOriginal())
	{
		if(_point->getYOriginal() > _targetMove->getYOriginal())
		{
			y--;
		}
		if(_point->getYOriginal() < _targetMove->getYOriginal())
		{
			y++;
		}
	}
	setPosition(new PPoint(x,y) );
}

void Character::goMove( int x, int y )
{
	CCLOG("unit x=%f y=%f  moveto x=%f y=%f", _point->getXOriginal(), _point->getYOriginal(), _targetMove->getXOriginal(), _targetMove->getYOriginal() );
	_targetMove = new PPoint(x * 50, y *50);
}

void Character::setPath(Path path)
{
	_path = path;
}

void Character::clearPath()
{
	_path.clear();
}

