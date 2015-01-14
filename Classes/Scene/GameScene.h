#ifndef GAME_SCENE_H__
#define GAME_SCENE_H__

#include "Scene/AbstractScene.h"
#include "Tools/Scroller.h"

#include "Controller/ReadLevel.h"
#include "Controller/SoundController.h"
#include "Controller/InterfaceGame.h"
#include "Controller/MapController.h"
#include "Common\common.h"

class GameScene : public AbstractScene {
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	InterfaceGame* _interfaceGame;
	Scroller* _scroll;
	MapController* _mapController;
	
	Touch _touchClick;

	bool isScrollMap(Touch* touch);
public:
	static GameScene* create(SoundController* soundController);
	virtual bool init(SoundController* soundController);

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

};

#endif // GAME_SCENE_H__