#pragma once
#ifndef LOGO_SCENE_H_
#define LOGO_SCENE_H_

#include "Scene/AbstractScene.h"
#include "MenuScene.h"


USING_NS_CC;

class LogoScene : public AbstractScene
{
private:
	Sprite* _logoImage;
	float _time;
public:
	static LogoScene* create();
	virtual bool init();
	void timeout(float dt);
};

#endif // LOGO_SCENE_H_