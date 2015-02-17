#ifndef ALERTQUESTIONSBOX_H__
#define ALERTQUESTIONSBOX_H__

#include "Tools/AlertBox.h"
#include "Model/Interface/Questions.h"
#include "Model/Interface/Question/KillQuestion.h"

class AlertQuestionsBox:public AlertBox
{
private:
	Questions* _questions;
	std::vector<Sprite*> _sprites;
	void addQuestions(Question* question, int n);
public:
	virtual bool init(Settings* settings);
	void setQuestions(Questions* questions);

};
#endif // ALERTQUESTIONSBOX_H__