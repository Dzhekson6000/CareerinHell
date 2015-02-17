#include "AlertQuestionsBox.h"

bool AlertQuestionsBox::init( Settings* settings )
{
	if(!AlertBox::init(settings)) {
		return false;
	}

	return true;
}

void AlertQuestionsBox::setQuestions( Questions* questions )
{
	_questions = questions;
	int i = 1;
	for(auto question: (*_questions->getQuestions()))
	{
		addQuestions(question, i);
		i++;
	}
	
}

void AlertQuestionsBox::addQuestions( Question* question, int n )
{
	Sprite* sprite = Sprite::create(PATH_INTERFACE "AlertBoxMenu.png");
	sprite->setPositionY( -((sprite->getContentSize().height+10) * n) + sprite->getContentSize().height/2 );
	_scroll->addChild(sprite);

	auto label = Label::createWithTTF( ((KillQuestion*)question)->getText(), "fonts/rupster.ttf", 36);
	label->setPosition(Point(sprite->getContentSize().width/2,sprite->getContentSize().height/2));
	sprite->addChild(label);

	_sprites.push_back(sprite);
}
