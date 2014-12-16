#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

struct Room
{
    int tip;     
};

class HelloWorld : public cocos2d::Layer
{
private:


public:
    static cocos2d::Scene* createScene();

    virtual bool init();  
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
