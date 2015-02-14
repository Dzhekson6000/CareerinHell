#ifndef Level_H_
#define Level_H_

#include "Model/Cell/TileCell.h"
#include "Model/Characters/Character.h"

class Character;
class TileCell;

class Level {

public:
	CC_SYNTHESIZE(std::vector<TileCell*>*, _tileCells, TileCells );
	CC_SYNTHESIZE(std::vector<Character*>*, _characters, Characters);
	CC_SYNTHESIZE(std::vector<Character*>*, _charactersAI, CharactersAI);
	CC_SYNTHESIZE(int**, _passageWays, PassageWays);
 	CC_SYNTHESIZE(int, _xMaxCell, XMaxCell);
	CC_SYNTHESIZE(int, _yMaxCell, YMaxCell);
	CC_SYNTHESIZE(int, _xMinCell, XMinCell);
	CC_SYNTHESIZE(int, _yMinCell, YMinCell);
	CC_SYNTHESIZE(int, _xPortalCell, XPortalCell);
	CC_SYNTHESIZE(int, _yPortalCell, YPortalCell);

	~Level(){
		delete _tileCells;
		delete _characters;
		delete _charactersAI;
		delete _passageWays;
	}
};
#endif /* Level_H_ */