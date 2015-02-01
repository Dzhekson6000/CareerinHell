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

	ReadLevel rl = ReadLevel();
	rl.readFile(PATH_MAP "home.xml");
	
	_scroll = Scroller::create();
	this->addChild(_scroll);

	_interfaceGame = InterfaceGame::create();
	this->addChild(_interfaceGame);

	_mapController = new MapController(rl.getLevel(), _scroll, _interfaceGame);

	std::vector<TileCell*>* tileCells = rl.getLevel()->getTileCells();
	for(time_t i = 0; i < tileCells->size(); i++)
	{
		std::vector<Cell*>* cells = tileCells->at(i)->getCells();
		for(time_t i = 0; i < cells->size(); i++)
		{
			_scroll->addChild(cells->at(cells->size() -1 -i)->getTexture());
		}
	}

	std::vector<Character*>* characters = rl.getLevel()->getCharacters();
	for(time_t i = 0; i < characters->size(); i++)
	{
		_interfaceGame->addCharacter(characters->at(characters->size() -1 -i   ));
		_scroll->addChild(characters->at(characters->size() -1 -i   ));
	}

	std::vector<Character*>* charactersAI = rl.getLevel()->getCharactersAI();
	for(time_t i = 0; i < charactersAI->size(); i++)
	{
		_scroll->addChild(charactersAI->at(charactersAI->size() -1 -i   ));
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
