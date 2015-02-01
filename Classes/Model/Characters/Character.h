#ifndef CHARACTERS_H__
#define CHARACTERS_H__

#include "cocos2d.h"
#include "Tools/PPoint.h"
#include "Common/common.h"

USING_NS_CC;

class Character : public Layer
{
private:
	int _width;
	int _height;
	bool _inversionX;
	bool _inversionY;
	int getInverse(bool inversion);
	PPoint* _targetMove; 
protected:
	int _id;
	PPoint* _point;
	Sprite* _sprite;
	Path	_path;
	void createSprite(std::string textureName);
public:
	Character(int id, PPoint* point);
	PPoint* getPPosition();
	int getId(){ return _id; };

	void setSize(int width, int height);
	void setPosition(PPoint* point);
	void setInversionX(bool inversion);
	void setInversionY(bool inversion);

	void update();
	void goMove(int x, int y);

	void setPath(Path path);
	void clearPath();
};

#endif // CHARACTERS_H__