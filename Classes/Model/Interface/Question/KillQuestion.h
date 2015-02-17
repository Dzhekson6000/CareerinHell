#ifndef KILLQUESTION_H_
#define KILLQUESTION_H_

#include "Question.h"

class KillQuestion:public Question {
private:
	int _id;
public:
	KillQuestion(Settings* settings, int id);
	std::string getText();
	void killEvent(int id);
};
#endif /* KILLQUESTION_H_ */