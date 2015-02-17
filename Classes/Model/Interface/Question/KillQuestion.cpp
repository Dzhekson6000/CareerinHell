#include "KillQuestion.h"

KillQuestion::KillQuestion(Settings* settings, int id ):Question(settings)
{
	_id = id;
}

void KillQuestion::killEvent( int id )
{
	if(_id == id)setPerformed(true);
}


std::string KillQuestion::getText()
{
	return _settings->getStringLocal()->getString("KillCharacter");
}
