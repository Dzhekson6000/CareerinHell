#ifndef ALERTBOX_H__
#define ALERTBOX_H__

#include "cocos2d.h"
#include "Common/common.h"
#include "Controller/Settings.h"

USING_NS_CC;

#define ALERT_CALLBACK_1(func, _Object) std::bind(&func,_Object, std::placeholders::_1)
typedef std::function<void(int)> onClick;
typedef std::function<void(std::string)> onClickString;

class AlertBox:public Layer
{
private:
	void initTouch();
	void createMask();

	Size _size;
	ClippingNode *_layerMask;

	bool _moved;
	float _yPosition;
	Point _offsetPoint;
	EventListenerTouchOneByOne* _touchListener;
	bool isScroll(Touch* touch);

	Sprite* fon;
	Sprite* closeButton;
protected:
	void createText(std::string text, std::string fontFile);
	Settings* _settings;
	Layer* _scroll;
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init(Settings* settings);

	virtual void click(Touch* touch){}

	void dead();
	void isClose(Touch* touch);
	bool _dead;
	virtual void deadChild(){};

	static AlertBox* create(Settings* settings);
};
#endif // ALERTBOX_H__