#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__

#include "common/common.h"
#include "Model/Characters/Character.h"
#include "Model/PMap.h"

class Pathfinder {
public:
	static void find(PPoint* point, Character* character, PMap* map);
};
 

#endif // _PATHFINDING_H_
