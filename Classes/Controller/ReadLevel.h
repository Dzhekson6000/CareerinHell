#ifndef __READ_LEVEL_H__
#define __READ_LEVEL_H__

#include <stdlib.h> //atoi
#include <math.h>//abs

#include <fstream>
#include "cocos2d.h"
#include "Tools/List.h"
#include "Level.h"

#include "Model/Wall.h"
#include "Model/Flooring.h"

#include <TinyXml/tinyxml.h>

USING_NS_CC;

class ReadLevel {
private:
public:
	Level* _level;
	ReadLevel();
	void readFile(std:: string fileName);

};

#endif // __READ_LEVEL_H__