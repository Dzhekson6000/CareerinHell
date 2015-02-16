#include "Cell.h"

Cell::Cell(PPoint point, PPoint* pointTile, std::string textureName, bool inversionX, bool inversionY)
{
	_inversionX = inversionX;
	_inversionY = inversionY;
	_texture = Sprite::create(textureName + ".png");
	_pointTile = pointTile;
	setPosition(point);
	_texture->setScaleX(getInverse(_inversionX));
	_texture->setScaleY(getInverse(_inversionY));
}

void Cell::updateOrder()
{
	_texture->setLocalZOrder(
		-(
		_pointTile->getXOriginal() + _point.getXOriginal()
			+
		_pointTile->getYOriginal() + _point.getYOriginal()
		)
		+ _order * 200
		);
}

void Cell::setPosition(PPoint point)
{
	_point = point;
	_texture->setPosition(_pointTile->getX() + point.getX(), _pointTile->getY() + point.getY() + _texture->getContentSize().height/2);
}

void Cell::setPositionTile(PPoint* point)
{
	_pointTile = point;
	_texture->setPosition(_pointTile->getX() + point->getX(), _pointTile->getY() + point->getY() + _texture->getContentSize().height/2);
}

void Cell::setOrder(int order)
{
	_order = order;
	updateOrder();
}

void Cell::setInversionX(bool inversion)
{
	_inversionX = inversion;
	_texture->setScaleX(getInverse(inversion));
}

void Cell::setInversionY(bool inversion)
{
	_inversionY = inversion;
	_texture->setScaleY(getInverse(inversion));
}

int Cell::getInverse(bool inversion)
{
	return inversion ? -1: 1;
}

Sprite* Cell::getTexture()
{
	return _texture;
}

int Cell::getCellX()
{
	return floor((_pointTile->getXOriginal() + _point.getXOriginal() )/50);
}

int Cell::getCellY()
{
	return floor((_pointTile->getYOriginal() + _point.getYOriginal() )/50);
}