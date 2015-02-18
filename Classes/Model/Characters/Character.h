#ifndef CHARACTERS_H__
#define CHARACTERS_H__

#include "cocos2d.h"
#include "Tools/PPoint.h"
#include "Common/common.h"
#include "Controller/Level.h"

class Level;

USING_NS_CC;

class Character : public Layer
{
private:
	bool _inversionX;
	bool _inversionY;
	int getInverse(bool inversion);

 	std::vector<PPoint> _path;
	void Character::findPath(PPoint* pointTarget, Level* level);
	void clearPath();
	
	/*property*/
	int _actionPoints;
	int _actionPointsMax;
	int _hitPoints;
	int _hitPointsMax;
	int _attackPoints;
protected:
	int _id;
	PPoint _point;
	Sprite* _sprite;
	Level* _level;
public:
	Character(int id, Level* level, PPoint point, std::string textureName);
	
	int getId(){ return _id; };

	PPoint* getPPosition();
	int getActionPoints(){return _actionPoints;}
	void setPPosition(PPoint point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	void transition();
	void update();
	void goMove(PPoint point);
	
	CC_SYNTHESIZE_READONLY(int, _actionXCell, ActionXCell);
	CC_SYNTHESIZE_READONLY(int, _actionYCell, ActionYCell);

	int getAttackPoints();
	void spendingActionPoints(int actionPoints);
	void attack(Character* character);

	bool isDead();

};

#endif // CHARACTERS_H__