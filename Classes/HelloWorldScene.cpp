#include "HelloWorldScene.h"

#include "Controller/ReadLevel.h"
#include "Tools\Scroller.h"
#include "Controller\InterfaceGame.h"

#define OFFSET    20

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

	_mapController = new MapController(rl.getLevel(), _scroll, _interfaceGame);

	std::vector<Cell*>* cells = rl.getLevel()->getCells();

	for(time_t i = 0; i < cells->size(); i++)
	{
		_scroll->addChild(cells->at(cells->size() -1 -i   )->getTexture() );
	}

	std::vector<Character*>* characters = rl.getLevel()->getCharacters();
	for(time_t i = 0; i < characters->size(); i++)
	{
		_interfaceGame->addCharacter(characters->at(characters->size() -1 -i   ));
		_scroll->addChild(characters->at(characters->size() -1 -i   )->getTexture() );
	}

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
	if(!isScrollMap(touch))
	{
		_mapController->click(touch);
	}
}

bool HelloWorld::isScrollMap(Touch* touch) {
	return std::abs(_touchClick.getLocation().x - touch->getLocation().x) > OFFSET || std::abs(_touchClick.getLocation().y - touch->getLocation().y) > OFFSET;
}
