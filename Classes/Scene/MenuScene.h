#ifndef MENU_SCENE_H__
#define MENU_SCENE_H__

#include "Scene/AbstractScene.h"
#include "Controller/MenuController.h"
#include "Controller/SoundController.h"
#include "Controller/ReadLocalization.h"
#include "Controller/Settings.h"
#include "GameScene.h"
#include "Common/common.h"

class MenuScene : public AbstractScene {

private:
	SoundController* _soundController;
	EventListenerTouchOneByOne* touchListener_;
	MenuController* menuController_;
	Settings* _settings;
public:
    static MenuScene* create();
    virtual bool init();  
    virtual bool TouchBegan(Touch* touch, Event* event);
	virtual void TouchMoved(Touch* touch, Event* event);
	virtual void TouchEnded(Touch* touch, Event* event);
	void setMenu(int item);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
};

#endif // MENU_SCENE_H__