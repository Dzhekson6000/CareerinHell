#ifndef MENU_SCENE_H__
#define MENU_SCENE_H__

#include "Tools/AbstractScene.h"
#include "Controller\MenuController.h"
#include "HelloWorldScene.h"

class MenuScene : public AbstractScene {

private:
	EventListenerTouchOneByOne* touchListener_;
	MenuController* menuController_;
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