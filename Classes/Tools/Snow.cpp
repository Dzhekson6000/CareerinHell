#include "Snow.h"

bool Snow::init()
{
	_snews = new std::vector<Sprite*>();
	srand( time(0) );

	this->schedule(schedule_selector(Snow::createSnow),0.10f);
	this->schedule(schedule_selector(Snow::update),0.01f);

	return true;
}

void Snow::update(float dt)
{
	for(time_t i = 0; i < _snews->size(); i++)
	{
		Sprite* sprite = _snews->at(i);
		sprite->setPosition(
			sprite->getPositionX() + 0.5,
			sprite->getPositionY() - 5
			);

		if(sprite->getPositionY() < -10)
		{
			this->removeChild(sprite);
			_snews->erase(_snews->begin() + i);
		}
	}
}

void Snow::createSnow(float dt)
{
	Sprite* sprite = Sprite::create(PATH_EXTRA "Snow.png");
	sprite->setPosition(
			rand()%1300,
			750
			);

	_snews->push_back(sprite);
	this->addChild(sprite);
}