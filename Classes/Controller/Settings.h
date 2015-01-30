#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "Tools/StringLocal.h"

class Settings
{
private:
	StringLocal* _stringLocal;
public:
	void setStringLocal(StringLocal* stringLocal){_stringLocal = stringLocal; }
	StringLocal* getStringLocal(){ return _stringLocal; }
};


#endif /* SETTINGS_H_ */