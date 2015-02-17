#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include "Question/Question.h"


class Questions {
private:
	std::vector<Question*> _questions;
public:
	Questions();
	void addQuestion(Question* questions);
	bool getPerformed();
	std::vector<Question*>* getQuestions();

	/*Events*/
	void killEvent(int id);
};
#endif /* QUESTIONS_H_ */