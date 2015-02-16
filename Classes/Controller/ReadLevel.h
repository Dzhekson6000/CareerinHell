#ifndef __READ_LEVEL_H__
#define __READ_LEVEL_H__

#include <stdlib.h> //atoi
#include <math.h>//abs

#include <fstream>
#include "cocos2d.h"
#include "Level.h"

#include "Model/Cell/Flooring.h"

#include "Model/Cell/Wall.h"
#include "Model/Cell/AngleWall.h"
#include "Model/Cell/IntersectionWall.h"
#include "Model/Cell/EndWall.h"
#include "Model/Cell/CellPortal.h"

#include "Model/Characters/Boat.h"

#include "Model/Object/Bed.h"
#include "Model/Object/Altar.h"

#include <TinyXml/tinyxml.h>

USING_NS_CC;

class ReadLevel {
private:
public:
	CC_SYNTHESIZE(Level*, _level, Level);
	ReadLevel();
	ReadLevel(std:: string fileName);
	void readFile(std:: string fileName);

};

#endif // __READ_LEVEL_H__