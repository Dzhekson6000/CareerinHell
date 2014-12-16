#ifndef Level_H_
#define Level_H_

#include "Model/Cell.h"
#include "Tools/List.h"

class Level {

private:
	

public:
	List<Cell*>* _cells;

	~Level(){
		delete _cells;
	}
};
#endif /* Level_H_ */