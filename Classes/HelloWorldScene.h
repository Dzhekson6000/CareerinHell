#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

#include "Controller/ReadLevel.h"
#include "Model\Weather\Snow.h"
#include "Tools\Scroller.h"
#include "Controller\InterfaceGame.h"
#include "Controller\MapController.h"

struct Room
{
    int tip;     
};

class HelloWorld : public cocos2d::Layer
{
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	InterfaceGame* _interfaceGame;
	Scroller* _scroll;
	MapController* _mapController;
	
	Touch _touchClick;
public:
    static cocos2d::Scene* createScene();

	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

    virtual bool init();  
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
