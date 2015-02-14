#include "AlertHiringBox.h"

AlertHiringBox::AlertHiringBox(Settings* settings)
{
	AlertBox::init(settings);
	_hiringUnits = Sprite::create(PATH_INTERFACE "HiringUnits.png");
	_hiringUnits->setPositionY(-(_hiringUnits->getContentSize().height/2) - 20);
	_scroll->addChild(_hiringUnits);
}

void AlertHiringBox::click( Touch* touch )
{
	float xClick = touch->getLocation().x - this->getPositionX();
	float yClick = touch->getLocation().y - this->getPositionY() - _scroll->getPositionY();
	float x = _hiringUnits->getPositionX();
	float y = _hiringUnits->getPositionY();
	float w = _hiringUnits->getContentSize().width;
	float h = _hiringUnits->getContentSize().height;
	if( (xClick>x-w/2) && (xClick<x+w/2) &&
		(yClick>y-h/2) && (yClick<y+h/2))
	{
		dead();
		_onClick(1);
	}	
}



