#include "InterfaceGame.h"

InterfaceGame* InterfaceGame::create(Settings* settings)
{
	InterfaceGame* scene = new InterfaceGame();
	if(scene && scene->init(settings)){
		return (InterfaceGame*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

bool InterfaceGame::init(Settings* settings)
{
	_settings = settings;
	_selectCharacter = NULL;
	_cardCharacters = new std::vector<CardCharacter*>;
	_cardCharacterLayer = Layer::create();
	this->addChild(_cardCharacterLayer);

	_spellbook = Sprite::create(PATH_INTERFACE  "spellbook.png");
	_spellbook->setPosition(1214, 83);
	this->addChild(_spellbook);


	_buttonEndCourse = Sprite::create(PATH_INTERFACE  "buttonEndCourse.png");
	_buttonEndCourse->setPosition(650, 64);
	this->addChild(_buttonEndCourse);

	initTouch();

	return true;
}

void InterfaceGame::initTouch()
{
	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(InterfaceGame::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(InterfaceGame::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(InterfaceGame::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 101);
}

void InterfaceGame::addCharacter(Character* character)
{
	CardCharacter* cardCharacter = new CardCharacter(character);//138x167
	cardCharacter->getTexture()->setPosition(70, 83.5+ (175 * _cardCharacters->size()) );
	this->addChild(cardCharacter->getTexture());

	_cardCharacters->push_back(cardCharacter);
}

bool InterfaceGame::isSelectCharacter()
{
	if(_selectCharacter != NULL) return true;
	return false;
}

bool InterfaceGame::isButEndCoClick( Touch* touch )
{
	float xClick = touch->getLocation().x;
	float yClick = touch->getLocation().y;
	float x = _buttonEndCourse->getPositionX();
	float y = _buttonEndCourse->getPositionY();
	float w = _buttonEndCourse->getContentSize().width;
	float h = _buttonEndCourse->getContentSize().height;
	if( (xClick>x-w/2) && (xClick<x+w/2) &&
		(yClick>y-h/2) && (yClick<y+h/2))
	{
		return true;
	}
	return false;
}

bool InterfaceGame::touchBegan(Touch* touch, Event* event)
{
	if(isInterfaceClick(touch))
	{
		_click = true;
	}
	return true;
}

void InterfaceGame::touchMoved(Touch* touch, Event* event)
{
}

void InterfaceGame::touchEnded(Touch* touch, Event* event)
{
	if(_click)
	{
		if(isInterfaceClick(touch) ){
		//клик по карте героя

			for(time_t i = 0; i < _cardCharacters->size(); i++)//определяем по какой карте
			{
				if(touch->getLocation().y > (175 * i) && touch->getLocation().y < 175 + (175 * i) )
				{
					 
					 if(isSelectCharacter() && _selectCharacter->getId() == _cardCharacters->at(i)->getCharacter()->getId())
					 {
						 _cardCharacters->at(i)->setSelect(false);
						 _selectCharacter = NULL;
					 } else {
						 cardClear();
						 _cardCharacters->at(i)->setSelect(true);
						_selectCharacter = _cardCharacters->at(i)->getCharacter();
					 }
					break;
				}
			}
		}
	}
	_click = false;
}

bool InterfaceGame::isInterfaceClick(Touch* touch)
{
	if(touch->getLocation().x < 138 && touch->getLocation().y < (175 * _cardCharacters->size()) )
		return true;

	return false;
}

void InterfaceGame::cardClear()
{
	for(time_t i = 0; i < _cardCharacters->size(); i++)//определяем по какой карте
	{
		_cardCharacters->at(i)->setSelect(false);
	}
}

bool InterfaceGame::isAlertBoxs()
{
	if(_alertBoxs.size() != 0)return true;
	return false;
}

void InterfaceGame::deadAlertBox()
{
	for(time_t i = 0; i < _alertBoxs.size(); i++)
	{
		if(_alertBoxs.at(i)->_dead)_alertBoxs.erase(_alertBoxs.begin()+i);
	}
}

void InterfaceGame::createHiringUnits()
{
	AlertHiringBox * alertHiringBox = new AlertHiringBox(_settings);
	alertHiringBox->setPosition(650, 360);
	alertHiringBox->addEventOnClick(_onHiringUnit);
	this->addChild(alertHiringBox);
	_alertBoxs.push_back(alertHiringBox);
}

void InterfaceGame::createPortalBox()
{
	AlertPortalBox * alertPortalBox = new AlertPortalBox(_settings);
	alertPortalBox->setPosition(650, 360);
	alertPortalBox->addEventOnClick(_onWarpPortal);
	this->addChild(alertPortalBox);
	_alertBoxs.push_back(alertPortalBox);
}
