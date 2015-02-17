#ifndef INTERFACEGAME_H__
#define INTERFACEGAME_H__

#include "cocos2d.h"
#include "Model/Interface/CardCharacter.h"
#include "Model/Characters/Character.h"
#include "Model/Interface/AlertBox/AlertHiringBox.h"
#include "Model/Interface/AlertBox/AlertPortalBox.h"
#include "Model/Interface/AlertBox/AlertQuestionsBox.h"
#include "Model/Interface/Questions.h"

USING_NS_CC;

#define INTERFACE_CALLBACK_0(func, _Object) std::bind(&func,_Object)
#define INTERFACE_CALLBACK_1(func, _Object) std::bind(&func,_Object, std::placeholders::_1)

typedef std::function<void(int)> OnHiringUnits;
typedef std::function<void(std::string)> OnWarpPortal;
typedef std::function<void()> OnTransition;

class CardCharacter;
class Character;

class InterfaceGame :public Layer
{
private:
	Settings* _settings;
	Sprite* _spellbook;
	Sprite* _buttonEndCourse;
	Sprite* _buttonQuestions;
	Layer* _cardCharacterLayer;
	std::vector<CardCharacter*> _cardCharacters;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	bool _click;

	void cardClear();

	std::vector<AlertBox*> _alertBoxs;
	void addAlertBox(AlertBox* alertBox);
	OnHiringUnits _onHiringUnit;
	OnWarpPortal _onWarpPortal;
	OnTransition _onTransition;

	bool isButEndCoClick(Touch* touch);
	bool isButQuestionsClick(Touch* touch);
	bool isSpriteClick(Touch* touch, Sprite* sprite);
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void createHiringUnits();
	void createPortalBox();
	void createQuestions();

	bool isInterfaceClick(Touch* touch);
	bool isAlertBoxs();
	void deadAlertBox();

	void addCharacter(Character* character);
	void clearCharacter();

	bool isSelectCharacter();

	CC_SYNTHESIZE_READONLY(Character*, _selectCharacter, SelectCharacter);

	static InterfaceGame* create(Settings* settings);
	virtual bool init(Settings* settings);

	void addEventOnHiringUnit(OnHiringUnits callback){ _onHiringUnit = callback; };
	void addEventOnWarpPortal(OnWarpPortal callback){ _onWarpPortal = callback; };
	void addEventOnTransition(OnTransition callback){ _onTransition = callback; };

	CC_SYNTHESIZE(Questions*, _questions, Questions);
};
#endif // INTERFACEGAME_H__