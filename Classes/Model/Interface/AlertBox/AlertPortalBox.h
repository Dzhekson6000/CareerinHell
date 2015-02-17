#ifndef ALERTPORTALBOX_H__
#define ALERTPORTALBOX_H__

#include "Tools/AlertBox.h"

class AlertPortalBox:public AlertBox
{
private:
	Sprite* _alertBoxMenu;

	onClickString _onClick;
public:
	virtual bool init(Settings* settings);

	void addEventOnClick(onClickString callback){ _onClick = callback; };
	void click(Touch* touch);

};
#endif // ALERTPORTALBOX_H__