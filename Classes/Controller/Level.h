#ifndef Level_H_
#define Level_H_

#include "Model\Cell\Cell.h"
#include "Model\Characters\Character.h"

class Level {

public:
	CC_SYNTHESIZE(std::vector<Cell*>*, _cells, Cells );
	CC_SYNTHESIZE(std::vector<Character*>*, _characters, Characters);

	~Level(){
		delete _cells;
		delete _characters;
	}
};
#endif /* Level_H_ */