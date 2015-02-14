#ifndef SCROLLER_H_
#define SCROLLER_H_

#include "cocos2d.h"

USING_NS_CC;

class Scroller : public Layer
{
private:
	void initTouch();
	EventListenerTouchOneByOne* _touchListener;

	Size _size;
	bool _moved;
	float _xPosition;
	float _yPosition;
	Point _offsetPoint;

public:
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);
	virtual bool init();
	bool isScrollMap(Touch* touch, const Point point);
	bool _notScroll;
	
	CREATE_FUNC(Scroller);
};


#endif /* SCROLLER_H_ */