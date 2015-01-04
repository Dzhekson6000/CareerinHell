#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	ReadLevel rl = ReadLevel();
	rl.readFile("map/home.xml");
	
	_scroll = Scroller::create();
	this->addChild(_scroll);

	_interfaceGame = InterfaceGame::create();
	this->addChild(_interfaceGame);

	Level* level = rl._level;
	for(int i = 0; i < level->_cells->size(); i++)
	{
		_scroll->addChild(level->_cells->get(level->_cells->size() -1 -i   )->getTexture() );
	}

	for(int i = 0; i < level->_characters->size(); i++)
	{
		_interfaceGame->addCharacter(level->_characters->get(level->_characters->size() -1 -i   ));
		_scroll->addChild(level->_characters->get(level->_characters->size() -1 -i   )->getTexture() );
	}

	_mapController = new MapController(level, _scroll, _interfaceGame);


	Snow * s = Snow::create();
	this->addChild(s);


	initTouch();

    return true;
}

void HelloWorld::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 103);
}

bool HelloWorld::touchBegan(Touch* touch, Event* event)
{
	_touchClick = *touch;
	return true;
}

void HelloWorld::touchMoved(Touch* touch, Event* event)
{
}

void HelloWorld::touchEnded(Touch* touch, Event* event)
{
	if(_touchClick.getLocation().x == touch->getLocation().x &&
		_touchClick.getLocation().y == touch->getLocation().y
		)
	{
		_mapController->click(touch);
	}
}