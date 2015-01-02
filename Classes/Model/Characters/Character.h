#ifndef CHARACTERS_H__
#define CHARACTERS_H__

#include "cocos2d.h"
#include "Tools/PPoint.h"

USING_NS_CC;

class Character
{
private:
	int _width;
	int _height;
	bool _inversionX;
	bool _inversionY;
	void updateInversion();
	void update();
protected:
	PPoint* _point;
	Sprite* _sprite;
	void createSprite(std::string textureName);
public:
	Character(PPoint* point);
	PPoint* getPosition();
	Sprite* getTexture();

	void setCenter(int width, int height);
	void setPosition(PPoint* point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);																			
};

#endif // CHARACTERS_H__