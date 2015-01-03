#ifndef CARDCHARACTERS_H__
#define CARDCHARACTERS_H__

#include "cocos2d.h"
#include "..\Characters\Character.h"

USING_NS_CC;

class CardCharacter
{
private:
	Sprite* _sprite;
	Character * _character;
public:
	CardCharacter(Character * character);
	void setCharacter(Character * character){_character = character;};
	Character* getCharacter(){return _character;};
	Sprite* getTexture(){return _sprite; };
};
#endif // CARDCHARACTERS_H__