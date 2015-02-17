#ifndef QUESTION_H_
#define QUESTION_H_

#include "cocos2d.h"
#include "Controller/Settings.h"

class Question {
	bool _isPerformed;
protected:
	void setPerformed(bool performed);
	Settings* _settings;
public:
	Question(Settings* settings);
	bool getPerformed();
	virtual std::string getText() {return "Not text";};
	virtual void killEvent(int id){};

};
#endif /* QUESTION_H_ */