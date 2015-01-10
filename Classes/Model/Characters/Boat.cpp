#include "Boat.h"

Boat::Boat(int id, PPoint* point,std::string tip,bool angle):Character(id, point)
{
	setInversionX(true);
	setSize(16, 77);

	std::string path = PATH_CHARACTERS + tip;

	createSprite(path);
}