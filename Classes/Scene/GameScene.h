#ifndef GAME_SCENE_H__
#define GAME_SCENE_H__

#include "Scene/AbstractScene.h"
#include "Tools/Scroller.h"
#include "Tools/StringLocal.h"

#include "Controller/ReadLevel.h"
#include "Controller/SoundController.h"
#include "Controller/Settings.h"
#include "Controller/InterfaceGame.h"
#include "Controller/GameController.h"
#include "Common/common.h"

class GameScene : public AbstractScene {
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	InterfaceGame* _interfaceGame;
	Scroller* _scroll;
	GameController* _mapController;
	
	Touch _touchClick;
	void update(float dt);
public:
	static GameScene* create(Settings* settings, SoundController* soundController);
	virtual bool init(Settings* settings, SoundController* soundController);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

};

#endif // GAME_SCENE_H__