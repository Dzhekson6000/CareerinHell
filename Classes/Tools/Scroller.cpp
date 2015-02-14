#include "Scroller.h"

#define OFFSET    20

bool Scroller::init()
{
	if ( !Layer::init() )  {
        return false;
    }
	
	_size = Director::getInstance()->getWinSize();
	_moved = false;
	_notScroll = false;

	initTouch();
	return true;
}

void Scroller::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(Scroller::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(Scroller::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(Scroller::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
}

bool Scroller::touchBegan(Touch* touch, Event* event)
{
	if(touch->getLocation().x < 138) return true;
	if(!_moved)
	{
		_moved = true;
		_xPosition = touch->getLocation().x;
		_yPosition = touch->getLocation().y;
	}

	_offsetPoint = touch->getLocation();
	return true;
}

void Scroller::touchMoved(Touch* touch, Event* event)
{

	if(touch->getLocation().x < 0 || touch->getLocation().x > _size.width) return;

	if(_moved && isScrollMap(touch, _offsetPoint))
	{
		this->setPositionX(this->getPositionX() + (touch->getLocation().x - _xPosition) );
		this->setPositionY(this->getPositionY() + (touch->getLocation().y - _yPosition) );

		_xPosition = touch->getLocation().x;
		_yPosition = touch->getLocation().y;
		
	}

}

bool Scroller::isScrollMap(Touch* touch, const Point point) {
	return (std::abs(point.x - touch->getLocation().x) > OFFSET || std::abs(point.y - touch->getLocation().y) > OFFSET) && !_notScroll;
}

void Scroller::touchEnded(Touch* touch, Event* event)
{
	_offsetPoint = touch->getLocation();
	_moved = false;
}