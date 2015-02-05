#include "AlertBox.h"


AlertBox* AlertBox::create(std::string text)
{
	AlertBox *pRet = new AlertBox();
	if (pRet && pRet->init(text))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool AlertBox::init()
{
	if ( !Layer::init() )  {
		return false;
	}

	_size = Size(1040,648);

	_moved = false;
	_yPosition = 0;

	//create fon
	Sprite* sprite = Sprite::create(PATH_INTERFACE "AlertBox.png");
	this->addChild(sprite);

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
	if(_moved)
	{
		_scroll->setPositionY(_scroll->getPositionY() + (touch->getLocation().y - _yPosition) );
		_yPosition = touch->getLocation().y;
	}

}

void AlertBox::touchEnded(Touch* touch, Event* event)
{
	_offsetPoint = touch->getLocation();
	_moved = false;
}

void AlertBox::createText(std::string text, std::string fontFile)
{
	Label* label = Label::createWithTTF(text.c_str(), fontFile.c_str(), 36, Size(_size.width -20, 0));
	label->setAnchorPoint(Point(0.5, 1));
	_scroll->addChild(label);
}
