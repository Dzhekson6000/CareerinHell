#ifndef __READ_LOCALIZATIO_H__
#define __READ_LOCALIZATIO_H__

#include <stdlib.h> //atoi
#include <math.h>//abs
#include "Common/common.h"

#include <fstream>
#include "cocos2d.h"

#include "Tools/StringLocal.h"

#include <TinyXml/tinyxml.h>

USING_NS_CC;

class ReadLocalization {
private:
	std::string _language;
public:
	CC_SYNTHESIZE(StringLocal*, _stringLocal, StringLocal);
	ReadLocalization();
	void readLocalization();
	void readLocalization(std::string language);

};

#endif // __READ_LOCALIZATIO_H__