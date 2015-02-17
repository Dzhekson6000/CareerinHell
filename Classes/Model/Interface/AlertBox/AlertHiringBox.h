#ifndef ALERTHIRINGBOX_H__
#define ALERTHIRINGBOX_H__

#include "Tools/AlertBox.h"

class AlertHiringBox:public AlertBox
{
private:
	Sprite* _hiringUnits;

	onClick _onClick;
public:
	virtual bool init(Settings* settings);

	void addEventOnClick(onClick callback){ _onClick = callback; };
	void click(Touch* touch);
};
#endif // ALERTHIRINGBOX_H__