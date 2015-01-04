#ifndef INTERFACEGAME_H__
#define INTERFACEGAME_H__

#include "cocos2d.h"
#include "Model\Interface\CardCharacter.h"
#include "Tools\List.h"

USING_NS_CC;

class InterfaceGame :public Layer
{
private:
	Sprite* _spellbook;
	Sprite* _buttonEnd—ourse;
	Layer* _cardCharacterLayer;
	List<CardCharacter*>* _cardCharacters;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	bool _click;
	Character* _selectCharacter;
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	bool isInterfaceClick(Touch* touch);

	void addCharacter(Character* character);

	bool isSelectCharacter();
	Character* getSelectCharacter(){ return _selectCharacter; };

	virtual bool init();  
    CREATE_FUNC(InterfaceGame);
};
#endif // INTERFACEGAME_H__