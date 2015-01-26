#ifndef ALERBOX_H__
#define ALERBOX_H__

#include "cocos2d.h"
#include "Common/common.h"

USING_NS_CC;

class AlertBox:public Layer
{
private:
	void initTouch();
	void createMask();

	Size _size;
	CCClippingNode *_layerMask;
	Layer* _scroll;

	bool _moved;
	float _yPosition;
	Point _offsetPoint;
	EventListenerTouchOneByOne* _touchListener;

public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init(std::string text);

	static AlertBox* create(std::string text);
};
#endif // ALERBOX_H__