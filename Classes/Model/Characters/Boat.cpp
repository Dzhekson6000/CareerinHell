#include "Boat.h"

Boat::Boat(int id, PPoint* point,std::string tip,bool angle):Character(id, point)
{
	setInversionX(true);
	setCenter(16, 77);

	std::string path = "img/characters/" + tip;

	createSprite(path);
}