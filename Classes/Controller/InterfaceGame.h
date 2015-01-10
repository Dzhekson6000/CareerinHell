#ifndef INTERFACEGAME_H__
#define INTERFACEGAME_H__

#include "cocos2d.h"
#include "Model/Interface/CardCharacter.h"

USING_NS_CC;

class InterfaceGame :public Layer
{
private:
	Sprite* _spellbook;
	Sprite* _buttonEnd—ourse;
	Layer* _cardCharacterLayer;
	std::vector<CardCharacter*>* _cardCharacters;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	bool _click;

	void cardClear();
	
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	bool isInterfaceClick(Touch* touch);

	void addCharacter(Character* character);

	bool isSelectCharacter();

	CC_SYNTHESIZE_READONLY(Character*, _selectCharacter, SelectCharacter);

	virtual bool init();  
    CREATE_FUNC(InterfaceGame);
};
#endif // INTERFACEGAME_H__