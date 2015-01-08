#include "CardCharacter.h"

CardCharacter::CardCharacter(Character * character)
{
	_character = character;
	_sprite = Layer::create();

	 _card = Sprite::create("img/interface/card.png");
	 _sprite->addChild(_card, 0);
	 _cardSelect = Sprite::create("img/interface/cardSelect.png");
	 _cardSelect->setVisible(false);
	 _sprite->addChild(_cardSelect, 0);
}

void CardCharacter::setSelect(bool select)
{
	if(select)
	{
		_card->setVisible(false);
		_cardSelect->setVisible(true);
	} else {
		_card->setVisible(true);
		_cardSelect->setVisible(false);
	}
}