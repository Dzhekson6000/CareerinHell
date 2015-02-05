#ifndef ALERTBOX_H__
#define ALERTBOX_H__

#include "cocos2d.h"
#include "Common/common.h"

USING_NS_CC;

class AlertBox:public Layer
{
private:
	void initTouch();
	void createMask();

	Size _size;
	ClippingNode *_layerMask;
	Layer* _scroll;

	bool _moved;
	float _yPosition;
	Point _offsetPoint;
	EventListenerTouchOneByOne* _touchListener;
	
protected:
	void createText(std::string text, std::string fontFile);
public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init();

	static AlertBox* create();
};
#endif // ALERTBOX_H__