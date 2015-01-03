#include "InterfaceGame.h"

bool InterfaceGame::init()
{
	_cardCharacters = new List<CardCharacter*>;
	_cardCharacterLayer = Layer::create();
	this->addChild(_cardCharacterLayer);

	_spellbook = Sprite::create("img/interface/spellbook.png");
	_spellbook->setPosition(1214, 83);
	this->addChild(_spellbook);


	_buttonEndСourse = Sprite::create("img/interface/buttonEndCourse.png");
	_buttonEndСourse->setPosition(650, 64);
	this->addChild(_buttonEndСourse);

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

	_cardCharacters->append(cardCharacter);
}

bool InterfaceGame::isSelectCharacter()
{
	if(_selectCharacter != nullptr) return true;
	return false;
}

bool InterfaceGame::touchBegan(Touch* touch, Event* event)
{
	if(touch->getLocation().x < 138)
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
		if(touch->getLocation().x < 138 && touch->getLocation().y < (175 * _cardCharacters->size()) ){
		//клик по карте героя

			for(int i = 0; i < _cardCharacters->size(); i++)//определяем по какой карте
			{
				if(touch->getLocation().y > (175 * i) && touch->getLocation().y < 175 + (175 * i) )
				{
					_selectCharacter = _cardCharacters->get(i)->getCharacter();
					break;
				}
			}
		}
	}
	_click = false;
}