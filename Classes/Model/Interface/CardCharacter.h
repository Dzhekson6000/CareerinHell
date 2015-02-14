#ifndef CARDCHARACTERS_H__
#define CARDCHARACTERS_H__

#include "cocos2d.h"
#include "Model/Characters/Character.h"
#include "Common/common.h"

USING_NS_CC;

class Character;

class CardCharacter
{
private:
	Sprite* _card;
	Sprite* _cardSelect;
public:
	CardCharacter(Character * character);
	CC_SYNTHESIZE(Character*, _character, Character);
	CC_SYNTHESIZE_READONLY(Layer*, _sprite, Texture);

	void setSelect(bool select);
};
#endif // CARDCHARACTERS_H__