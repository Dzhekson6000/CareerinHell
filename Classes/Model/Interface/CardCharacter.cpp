#include "CardCharacter.h"

CardCharacter::CardCharacter(Character * character)
{
	_character = character;
	_sprite = Sprite::create("img/interface/card.png");
}