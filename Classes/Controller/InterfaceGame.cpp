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
	_questions = NULL;
	_cardCharacterLayer = Layer::create();
	this->addChild(_cardCharacterLayer);

	_spellbook = Sprite::create(PATH_INTERFACE  "spellbook.png");
	_spellbook->setPosition(1214, 83);
	this->addChild(_spellbook);


	_buttonEndCourse = Sprite::create(PATH_INTERFACE  "buttonEndCourse.png");
	_buttonEndCourse->setPosition(650, 64);
	this->addChild(_buttonEndCourse);

	_buttonQuestions = Sprite::create(PATH_INTERFACE  "questionButton.png");
	_buttonQuestions->setPosition(1238, 666);
	this->addChild(_buttonQuestions);


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
	cardCharacter->getTexture()->setPosition(70, 83.5+ (175 * _cardCharacters.size()) );
	this->addChild(cardCharacter->getTexture());
	_cardCharacters.push_back(cardCharacter);
}

void InterfaceGame::clearCharacter()
{
	for(auto cardCharacter: _cardCharacters)
	{
		this->removeChild(cardCharacter->getTexture());
		delete cardCharacter;
	}
	_cardCharacters.clear();
}

bool InterfaceGame::isSelectCharacter()
{
	if(_selectCharacter != NULL) return true;
	return false;
}

bool InterfaceGame::isButEndCoClick( Touch* touch )
{
	if( isSpriteClick(touch, _buttonEndCourse) )
	{
		return true;
	}
	return false;
}


bool InterfaceGame::isButQuestionsClick( Touch* touch )
{
	if( isSpriteClick(touch, _buttonQuestions) )
	{
		return true;
	}
	return false;
}

bool InterfaceGame::isSpriteClick(Touch* touch, Sprite* sprite )
{
	if( (touch->getLocation().x>sprite->getPositionX()-sprite->getContentSize().width/2) && (touch->getLocation().x<sprite->getPositionX()+sprite->getContentSize().width/2) &&
		(touch->getLocation().y>sprite->getPositionY()-sprite->getContentSize().height/2) && (touch->getLocation().y<sprite->getPositionY()+sprite->getContentSize().height/2))
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

			if(isButEndCoClick(touch ) )
			{
				_onTransition();
				_click = false;
				return;
			}

			if(isButQuestionsClick(touch))
			{
				createQuestions();
				_click = false;
				return;
			}

			for(time_t i = 0; i < _cardCharacters.size(); i++)
			{
				if(touch->getLocation().y > (175 * i) && touch->getLocation().y < 175 + (175 * i) )
				{
					 
					 if(isSelectCharacter() && _selectCharacter->getId() == _cardCharacters.at(i)->getCharacter()->getId())
					 {
						 _cardCharacters.at(i)->setSelect(false);
						 _selectCharacter = NULL;
					 } else {
						 cardClear();
						 _cardCharacters.at(i)->setSelect(true);
						_selectCharacter = _cardCharacters.at(i)->getCharacter();
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
	if(touch->getLocation().x < 138 && touch->getLocation().y < (175 * _cardCharacters.size()) )
		return true;
	if(isButEndCoClick(touch))return true;
	if(isButQuestionsClick(touch))return true;
	return false;
}

void InterfaceGame::cardClear()
{
	for(time_t i = 0; i < _cardCharacters.size(); i++)//���������� �� ����� �����
	{
		_cardCharacters.at(i)->setSelect(false);
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
	AlertHiringBox * alertHiringBox = AlertBox::create< AlertHiringBox >( _settings );
	alertHiringBox->addEventOnClick(_onHiringUnit);
	addAlertBox(alertHiringBox);
}

void InterfaceGame::createPortalBox()
{
	AlertPortalBox * alertPortalBox = AlertBox::create< AlertPortalBox >( _settings );
	alertPortalBox->addEventOnClick(_onWarpPortal);
	addAlertBox(alertPortalBox);
}

void InterfaceGame::createQuestions()
{
	if(_questions != NULL)
	{
		AlertQuestionsBox* alertQuestionsBox = AlertBox::create<AlertQuestionsBox>(_settings);
		alertQuestionsBox->setQuestions(_questions);
		addAlertBox(alertQuestionsBox);
	}
}

void InterfaceGame::addAlertBox( AlertBox* alertBox )
{
	alertBox->setPosition(650, 360);
	this->addChild(alertBox);
	_alertBoxs.push_back(alertBox);
}