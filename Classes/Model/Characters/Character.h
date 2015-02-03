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
	int _width;
	int _height;
	bool _inversionX;
	bool _inversionY;
	int getInverse(bool inversion);
 	std::vector<PPoint*>* _path;
	void Character::findPath(PPoint* pointTarget, Level* level);
	void clearPath();
protected:
	int _id;
	PPoint* _point;
	Sprite* _sprite;
	void createSprite(std::string textureName);
public:
	Character(int id, PPoint* point);
	PPoint* getPPosition();
	int getId(){ return _id; };

	void setSize(int width, int height);
	void setPPosition(PPoint* point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	void update();
	void goMove(PPoint* point, Level* level);
	
};

#endif // CHARACTERS_H__