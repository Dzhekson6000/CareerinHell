#ifndef Level_H_
#define Level_H_

#include "Model/Cell/TileCell.h"
#include "Model/Characters/Character.h"

class Character;
class TileCell;

class Level {

public:
	CC_SYNTHESIZE(std::vector<TileCell*>, _tileCells, TileCells );
	CC_SYNTHESIZE(std::vector<Character*>, _characters, Characters);
	CC_SYNTHESIZE(std::vector<Character*>, _charactersAI, CharactersAI);
	CC_SYNTHESIZE(int**, _passageWays, PassageWays);
 	CC_SYNTHESIZE(int, _xMaxCell, XMaxCell);
	CC_SYNTHESIZE(int, _yMaxCell, YMaxCell);
	CC_SYNTHESIZE(int, _xMinCell, XMinCell);
	CC_SYNTHESIZE(int, _yMinCell, YMinCell);
	CC_SYNTHESIZE(int, _xPortalCell, XPortalCell);
	CC_SYNTHESIZE(int, _yPortalCell, YPortalCell);

	Level()
	{
		_xMaxCell = 0;
		_yMaxCell = 0;
		_xMinCell = 0;
		_yMinCell = 0;
		_xPortalCell = NULL;
		_yPortalCell = NULL;
	}

	void release()
	{
		_tileCells.clear();
		_characters.clear();
		_charactersAI.clear();
	}

	~Level(){
	}
};
#endif /* Level_H_ */