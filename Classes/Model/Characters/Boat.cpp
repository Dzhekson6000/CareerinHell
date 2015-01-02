#include "Boat.h"

Boat::Boat(PPoint* point,std::string tip,bool angle):Character(point)
{
	setInversionX(true);
	setCenter(16, 77);

	std::string path = "img/characters/" + tip;

	createSprite(path);
}