#ifndef Level_H_
#define Level_H_

#include "Model/Cell/TileCell.h"
#include "Model/Characters/Character.h"

class Level {

public:
	CC_SYNTHESIZE(std::vector<TileCell*>*, _tileCells, TileCells );
	CC_SYNTHESIZE(std::vector<Character*>*, _characters, Characters);
	CC_SYNTHESIZE(std::vector<Character*>*, _charactersAI, CharactersAI);

	~Level(){
		delete _tileCells;
		delete _characters;
	}
};
#endif /* Level_H_ */