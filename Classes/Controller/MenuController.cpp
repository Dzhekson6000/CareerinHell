#include "Controller\MenuController.h"
void MenuController::init(Settings* _settings){

	_fon = Sprite::create(PATH_IMG  "MenuSceneFon.png");
	_fon->setPosition(Point(620, 360));

	_buttonNext = Sprite::create(PATH_IMG  "MenuSceneButtonNext.png");
	_buttonNext->setPosition(Point(620, 360));
	auto labelButtonNext = Label::createWithTTF(_settings->getStringLocal()->getString("ResumeGame").c_str(), "fonts/rupster.ttf", 36);
	labelButtonNext->setPosition(Point(650, 613.5));
	_buttonNext->addChild(labelButtonNext);

	_buttonNewGame = Sprite::create(PATH_IMG  "MenuSceneButtonNewGame.png");
	_buttonNewGame->setPosition(Point(620, 360));
	auto labelButtonNewGame = Label::createWithTTF(_settings->getStringLocal()->getString("NewGame").c_str(), "fonts/rupster.ttf", 36);
	labelButtonNewGame->setPosition(Point(650, 384.5));
	_buttonNewGame->addChild(labelButtonNewGame);

	_buttonExit = Sprite::create(PATH_IMG  "MenuSceneButtonExit.png");
	_buttonExit->setPosition(Point(620, 360));
	auto labelButtonExit = Label::createWithTTF(_settings->getStringLocal()->getString("Exit").c_str(), "fonts/rupster.ttf", 36);
	labelButtonExit->setPosition(Point(650, 163.5));
	_buttonExit->addChild(labelButtonExit);

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