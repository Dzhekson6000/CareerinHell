#ifndef __MAP_H__
#define __MAP_H__

#include "cocos2d.h"

class PMap {
public:
	int** _passageWays;
	CC_SYNTHESIZE(int, _xMax, Width);
	CC_SYNTHESIZE(int, _yMax, Height);
};


#endif // __MAP_H__
