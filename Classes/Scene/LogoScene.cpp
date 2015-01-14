#include "LogoScene.h"


LogoScene* LogoScene::create() {
	LogoScene* scene = new LogoScene();
	if(scene && scene->init()){
		return (LogoScene*)scene->autorelease();
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

bool LogoScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	_time = 0;

	_logoImage  = Sprite::create(PATH_IMG "Logo.png");
	_logoImage->setPosition(Point(650,360));
	this->addChild(_logoImage,0);


	this->schedule(schedule_selector(LogoScene::timeout),1.00f);//таймер до завершение показа логотипа
	

	scene_ = Scene::create();
	scene_->addChild(this);
    return true;
}

void LogoScene::timeout(float dt)
{
	_time+=dt;
	if(_time > 0.5)
	{
		Director::getInstance()->replaceScene(MenuScene::create()->getScene());//переходим на главное окно
	}

}