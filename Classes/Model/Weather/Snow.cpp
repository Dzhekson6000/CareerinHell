#include "Snow.h"

bool Snow::init()
{
	_snews = new List<Sprite*>();
	srand( time(0) );

	this->schedule(schedule_selector(Snow::createSnow),0.10f);
	this->schedule(schedule_selector(Snow::update),0.01f);

	return true;
}

void Snow::update(float dt)
{
	for(int i = 0; i < _snews->size(); i++)
	{
		Sprite* sprite = _snews->get(i);
		sprite->setPosition(
			sprite->getPositionX() + 0.5,
			sprite->getPositionY() - 5
			);

		if(sprite->getPositionY() < -10)
		{
			this->removeChild(sprite);
			_snews->remove(i);
		}
	}
}

void Snow::createSnow(float dt)
{
	Sprite* sprite = Sprite::create("img/extra/Snow.png");
	sprite->setPosition(
			rand()%1300,
			750
			);

	_snews->append(sprite);
	this->addChild(sprite);
}