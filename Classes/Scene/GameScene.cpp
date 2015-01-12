#include "GameScene.h"

#define OFFSET    20

GameScene* GameScene::create(SoundController* soundController)
{
	GameScene* scene = new GameScene();
	if(scene && scene->init(soundController)){
		return (GameScene*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

bool GameScene::init(SoundController* soundController)
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
		PPoint * point =  cells->at(cells->size() -1 -i)->getPosition();
		_scroll->addChild(cells->at(cells->size() -1 -i)->getTexture(),
			-(point->getXOriginal() + point->getYOriginal()) + cells->at(cells->size() -1 -i)->getOrder() * 200
			);
	}

	std::vector<Character*>* characters = rl.getLevel()->getCharacters();
	for(time_t i = 0; i < characters->size(); i++)
	{
		_interfaceGame->addCharacter(characters->at(characters->size() -1 -i   ));
		_scroll->addChild(characters->at(characters->size() -1 -i   )->getTexture() );
	}

	initTouch();
  	
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
	_touchClick = *touch;
	return true;
}

void GameScene::touchMoved(Touch* touch, Event* event)
{
}

void GameScene::touchEnded(Touch* touch, Event* event)
{
	if(!isScrollMap(touch))
	{
		_mapController->click(touch);
	}
}

bool GameScene::isScrollMap(Touch* touch) {
	return std::abs(_touchClick.getLocation().x - touch->getLocation().x) > OFFSET || std::abs(_touchClick.getLocation().y - touch->getLocation().y) > OFFSET;
}