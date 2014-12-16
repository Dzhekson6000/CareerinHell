#include "Controller\MenuController.h"
void MenuController::init(){

	_fon = Sprite::create("img/MenuSceneFon.png");
	_fon->setPosition(Point(620, 360));

	_buttonNext = Sprite::create("img/MenuSceneButtonNext.png");
	_buttonNext->setPosition(Point(620, 360));

	_buttonNewGame = Sprite::create("img/MenuSceneButtonNewGame.png");
	_buttonNewGame->setPosition(Point(620, 360));

	_buttonExit = Sprite::create("img/MenuSceneButtonExit.png");
	_buttonExit->setPosition(Point(620, 360));

}
int MenuController::selectMenuItem(int x, int y, bool isTouch){
	int item = 0;
	
	if(x <  260 || x > 1040 ) return 0;

	if(y >= 550 && y < 676){
		item = 1;
	} else
	if(y >= 322 && y < 448){
		item = 2;
	} else
	if(y >= 100 && y < 227){
		item = 3;
	}

	if(!isTouch){
		return item;
	} else {
		return 0;
	}
}