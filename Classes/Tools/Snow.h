#ifndef SNOW_H__
#define SNOW_H__

#include "cocos2d.h"
#include "Tools/PPoint.h"
USING_NS_CC;

class Snow : public Layer
{
private:
	std::vector<Sprite*>* _snews;
public:
	void update(float dt);
	void createSnow(float dt);
	virtual bool init();
	CREATE_FUNC(Snow);
};

#endif // SNOW_H__