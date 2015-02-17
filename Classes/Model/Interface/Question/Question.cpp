#include "Question.h"

Question::Question(Settings* settings)
{
	_settings = settings;
	_isPerformed = false;
}

void Question::setPerformed( bool performed )
{
	_isPerformed = performed;
}

bool Question::getPerformed()
{
	return _isPerformed;
}
