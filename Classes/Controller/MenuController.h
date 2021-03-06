#ifndef MENU_CONTROLLER_H_
#define MENU_CONTROLLER_H_

#include "cocos2d.h"
#include "Common/common.h"
#include "Controller/Settings.h"

USING_NS_CC;
class MenuController{

	Sprite* _fon;
	Sprite* _buttonNext;
	Sprite* _buttonNewGame;
	Sprite* _buttonExit;
	Settings* _settings;

public:
	int selectMenuItem(int x, int y, bool isTouch);
	void init(Settings* settings);
	Sprite* getFon(){return _fon;}
	Sprite* getButtonNext(){return _buttonNext;}
	Sprite* getButtonNewGame(){return _buttonNewGame;}
	Sprite* getButtonExit(){return _buttonExit;}
};
#endif /* MENU_CONTROLLER_H_ */
