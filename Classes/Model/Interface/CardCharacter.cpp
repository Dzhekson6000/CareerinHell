#include "CardCharacter.h"

CardCharacter::CardCharacter(Character * character)
{
	_character = character;
	_sprite = Layer::create();

	 _card = Sprite::create(PATH_INTERFACE + "card.png");
	 _sprite->addChild(_card, 0);
	 _cardSelect = Sprite::create(PATH_INTERFACE + "cardSelect.png");
	 _cardSelect->setVisible(false);
	 _sprite->addChild(_cardSelect, 0);
}

void CardCharacter::setSelect(bool select)
{
	_card->setVisible(!select);
	_cardSelect->setVisible(select);
}