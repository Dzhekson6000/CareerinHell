#ifndef Level_H_
#define Level_H_

#include "Model/Cell/Cell.h"
#include "Tools/List.h"
#include "Model\Characters\Character.h"


class Level {

private:
	

public:
	List<Cell*>* _cells;
	List<Character*>* _characters;

	~Level(){
		delete _cells;
	}
};
#endif /* Level_H_ */