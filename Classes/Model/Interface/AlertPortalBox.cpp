#include "AlertPortalBox.h"


AlertPortalBox::AlertPortalBox(Settings* settings)
{
	AlertBox::init(settings);
	_alertBoxMenu = Sprite::create(PATH_INTERFACE "AlertBoxMenu.png");
	_alertBoxMenu->setPositionY(-(_alertBoxMenu->getContentSize().height/2) - 20);
	_scroll->addChild(_alertBoxMenu);

	auto labelButtonLoc = Label::createWithTTF(_settings->getStringLocal()->getString("Loc").c_str(), "fonts/rupster.ttf", 36);
	labelButtonLoc->setPosition(Point(_alertBoxMenu->getContentSize().width/2,_alertBoxMenu->getContentSize().height/2));
	_alertBoxMenu->addChild(labelButtonLoc);
}

void AlertPortalBox::click( Touch* touch )
{
	float xClick = touch->getLocation().x - this->getPositionX();
	float yClick = touch->getLocation().y - this->getPositionY() - _scroll->getPositionY();
	float x = _alertBoxMenu->getPositionX();
	float y = _alertBoxMenu->getPositionY();
	float w = _alertBoxMenu->getContentSize().width;
	float h = _alertBoxMenu->getContentSize().height;
	if( (xClick>x-w/2) && (xClick<x+w/2) &&
		(yClick>y-h/2) && (yClick<y+h/2))
	{
		dead();
		_onClick("home.xml");

	}
}
