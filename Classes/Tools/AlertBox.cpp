#include "AlertBox.h"

#define OFFSET    20

bool AlertBox::init(Settings* settings)
{
	if ( !Layer::init() )  {
		return false;
	}

	_settings = settings;
	_dead = false;
	_size = Size(1040,648);

	_moved = false;
	_yPosition = 0;

	//create fon
	fon = Sprite::create(PATH_INTERFACE "AlertBox.png");
	this->addChild(fon);

	closeButton = Sprite::create(PATH_INTERFACE "CloseAlertBox.png");
	closeButton->setPosition( Point(520, 324) );
	this->addChild(closeButton);

	_scroll = Layer::create();
	_scroll->setPosition( Point(0, _size.height/2) );
	

	createMask();
	_layerMask->addChild(_scroll);
	this->addChild(_layerMask);

	initTouch();
	return true;
}

void AlertBox::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(AlertBox::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(AlertBox::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(AlertBox::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);
}

void AlertBox::createMask()
{
	//create maskbox
	static Point maskbox[4];
	maskbox[0] = Point(-(_size.width/2), -(_size.height/2)); 
	maskbox[1] = Point(-(_size.width/2),  (_size.height/2));
	maskbox[2] = Point( (_size.width/2),  (_size.height/2));
	maskbox[3] = Point( (_size.width/2), -(_size.height/2));

	DrawNode *_mask = DrawNode::create();
	_mask->drawPolygon(maskbox, 4, Color4F(0,0,0,1), 0, Color4F(0,0,0,1));

	_layerMask = ClippingNode::create();
	_layerMask->setInverted(false); 
	_layerMask->setStencil(_mask);


}

bool AlertBox::touchBegan(Touch* touch, Event* event)
{
	if(_dead)return true;
	if(!_moved)
	{
		_moved = true;
		_yPosition = touch->getLocation().y;
	}

	_offsetPoint = touch->getLocation();
	return true;
}

void AlertBox::touchMoved(Touch* touch, Event* event)
{
	if(_dead)return;
	if(_moved)
	{
		if(_size.height/2 > _scroll->getPositionY() + (touch->getLocation().y - _yPosition))
			_scroll->setPositionY(_scroll->getPositionY() + (touch->getLocation().y - _yPosition) );
		_yPosition = touch->getLocation().y;
	}

}

void AlertBox::touchEnded(Touch* touch, Event* event)
{
	if(_dead)return;
	if(!isScroll(touch))
	{
		click(touch);
		isClose(touch);

	}
	_offsetPoint = touch->getLocation();
	_moved = false;
}

bool AlertBox::isScroll(Touch* touch) {
	return std::abs(_offsetPoint.x - touch->getLocation().x) > OFFSET || std::abs(_offsetPoint.y - touch->getLocation().y) > OFFSET;
}

void AlertBox::createText(std::string text, std::string fontFile)
{
	Label* label = Label::createWithTTF(text.c_str(), fontFile.c_str(), 36, Size(_size.width -20, 0));
	label->setAnchorPoint(Point(0.5, 1));
	_scroll->addChild(label);
}

void AlertBox::isClose(Touch* touch)
{
	float xClick = touch->getLocation().x;
	float yClick = touch->getLocation().y;
	float x = 1170;
	float y = 684;
	float w,h; w = h = 54;
	if( (xClick>x-w/2) && (xClick<x+w/2) &&
		(yClick>y-h/2) && (yClick<y+h/2))
	{
		//Close
		dead();
		return;
	}
	//not Close
	return;
}

void AlertBox::dead()
{
	_dead = true;
	this->removeAllChildren();
	deadChild();
}
