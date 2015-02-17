#include "Questions.h"

Questions::Questions()
{
}

void Questions::addQuestion( Question* questions )
{
	_questions.push_back(questions);
}

void Questions::killEvent( int id )
{
	for(auto question:_questions)
	{
		question->killEvent(id);
	}
}

bool Questions::getPerformed()
{
	for(auto question:_questions)
	{
		if(!question->getPerformed())return false;
	}
	return true;
}

std::vector<Question*>* Questions::getQuestions()
{
	return &_questions;
}
