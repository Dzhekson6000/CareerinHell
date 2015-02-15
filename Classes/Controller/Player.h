#ifndef PLAYER_H_
#define PLAYER_H_

#include "cocos2d.h"
#include "Model/Characters/Character.h"

USING_NS_CC;



class Player {

public:
	CC_SYNTHESIZE(int, _nCharacter, NCharacter);
	CC_SYNTHESIZE(std::vector<Character*>*, _characters, Characters);
	int augmentN(){_nCharacter++; return _nCharacter;};

	~Player(){
		
	}
};
#endif /* PLAYER_H_ */