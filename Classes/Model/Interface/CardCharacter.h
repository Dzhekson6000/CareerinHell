#ifndef CARDCHARACTERS_H__
#define CARDCHARACTERS_H__

#include "cocos2d.h"
#include "..\Characters\Character.h"

USING_NS_CC;

class CardCharacter
{

public:
	CardCharacter(Character * character);
	CC_SYNTHESIZE(Character*, _character, Character);
	CC_SYNTHESIZE_READONLY(Sprite*, _sprite, Texture);
};
#endif // CARDCHARACTERS_H__