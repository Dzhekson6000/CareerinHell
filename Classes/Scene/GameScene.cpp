#include "GameScene.h"

#define OFFSET    20

GameScene* GameScene::create(Settings* settings, SoundController* soundController)
{
	GameScene* scene = new GameScene();
	if(scene && scene->init(settings, soundController)){
		return (GameScene*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

bool GameScene::init(Settings* settings, SoundController* soundController)
{
    if ( !Layer::init() )
    {
        return false;
    }
	
	_scroll = Scroller::create();
	this->addChild(_scroll);

	_interfaceGame = InterfaceGame::create(settings);
	this->addChild(_interfaceGame);

	_mapController = new GameController(_scroll, _interfaceGame);
	initTouch();

	this->schedule(schedule_selector(GameScene::update),0.01f);

	scene_ = Scene::create();
	scene_->addChild(this);

	return true;
}

void GameScene::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 103);
}

bool GameScene::touchBegan(Touch* touch, Event* event)
{
	_interfaceGame->deadAlertBox();
	_scroll->_notScroll = _interfaceGame->isAlertBoxs();
	_touchClick = *touch;
	return true;
}

void GameScene::touchMoved(Touch* touch, Event* event)
{
}

void GameScene::touchEnded(Touch* touch, Event* event)
{
	if(!_scroll->isScrollMap(touch, _touchClick.getLocation() ))
	{
		_mapController->click(touch);
	}
}

void GameScene::update( float dt )
{
	_mapController->update(dt);
}
