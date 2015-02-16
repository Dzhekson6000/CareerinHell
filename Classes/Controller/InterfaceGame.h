#ifndef INTERFACEGAME_H__
#define INTERFACEGAME_H__

#include "cocos2d.h"
#include "Model/Interface/CardCharacter.h"
#include "Model/Characters/Character.h"
#include "Model/Interface/AlertHiringBox.h"
#include "Model/Interface/AlertPortalBox.h"

USING_NS_CC;

#define INTERFACE_CALLBACK_1(func, _Object) std::bind(&func,_Object, std::placeholders::_1)

typedef std::function<void(int)> OnHiringUnits;
typedef std::function<void(std::string)> OnWarpPortal;

class CardCharacter;
class Character;

class InterfaceGame :public Layer
{
private:
	Settings* _settings;
	Sprite* _spellbook;
	Sprite* _buttonEndCourse;
	Layer* _cardCharacterLayer;
	std::vector<CardCharacter*> _cardCharacters;

	void initTouch();
	EventListenerTouchOneByOne* _touchListener;
	bool _click;

	void cardClear();

	std::vector<AlertBox*> _alertBoxs;
	OnHiringUnits _onHiringUnit;
	OnWarpPortal _onWarpPortal;
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void createHiringUnits();
	void createPortalBox();

	bool isInterfaceClick(Touch* touch);
	bool isButEndCoClick(Touch* touch);
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
};
#endif // INTERFACEGAME_H__