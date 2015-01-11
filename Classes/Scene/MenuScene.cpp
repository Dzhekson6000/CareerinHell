#include "MenuScene.h"
#include "SimpleAudioEngine.h"



MenuScene* MenuScene::create()
{
	MenuScene* scene = new MenuScene();
	if(scene && scene->init()) return (MenuScene*)scene->autorelease();
	CC_SAFE_DELETE(scene);
	return scene;
}

bool MenuScene::init() {

    if (!Layer::init()) {
        return false;
    }

	_soundController = new SoundController();
	_soundController->preloadEffect(ES_FIRE);
	_soundController->preloadMusic("sound/1.wav");
	_soundController->preloadMusic("sound/2.wav");
	_soundController->preloadMusic("sound/3.wav");
	_soundController->preloadMusic("sound/4.wav");
	_soundController->preloadMusic("sound/5.wav");

	menuController_ = new MenuController();
	menuController_->init();

	touchListener_ = EventListenerTouchOneByOne::create();
	touchListener_->onTouchBegan = CC_CALLBACK_2(MenuScene::TouchBegan,this);
	touchListener_->onTouchMoved = CC_CALLBACK_2(MenuScene::TouchMoved, this);
	touchListener_->onTouchEnded = CC_CALLBACK_2(MenuScene::TouchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(touchListener_, 100);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	setTouchMode(kCCTouchesOneByOne);
    
	this->addChild(menuController_->getFon(), 0);
	this->addChild(menuController_->getButtonNext(), 1);
	this->addChild(menuController_->getButtonNewGame(), 1);
	this->addChild(menuController_->getButtonExit(), 1);
  
	this->setKeyboardEnabled(true);

	scene_ = Scene::create();
	scene_->addChild(this);

    return true;
}

void MenuScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event){
	if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 && keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)) {
		Director::getInstance()->end();
	}
}

bool MenuScene::TouchBegan(Touch *touch, Event *event) {
	setMenu(menuController_->selectMenuItem(touch->getLocation().x, touch->getLocation().y, true));
    return true;
}

void MenuScene::TouchMoved(Touch* touch, Event* event) {
	setMenu(menuController_->selectMenuItem(touch->getLocation().x, touch->getLocation().y, true));
}

void MenuScene::TouchEnded(Touch* touch, Event* event) {
	setMenu(menuController_->selectMenuItem(touch->getLocation().x, touch->getLocation().y, false));	
}

 void MenuScene::setMenu(int item){
 switch (item) {
		case 1:
			//клик на кнопку продолжить
			_soundController->playEffect(ES_FIRE);
			getEventDispatcher()->removeEventListener(touchListener_);
			Director::getInstance()->pushScene(GameScene::create(_soundController)->getScene() );
			break;
		case 2:
			//клик на кнопку новая игра
			_soundController->playEffect(ES_FIRE);
			//getEventDispatcher()->removeEventListener(touchListener_);
			//Director::getInstance()->pushScene(LevelMenuScene::create()->getScene());
			break;
		case 3:
			//клик на кнопку выход
			_soundController->playEffect(ES_FIRE);
			Director::getInstance()->end();
			break;
		default:
			break;
		}
 }