#include "Boat.h"

Boat::Boat(int id, PPoint* point,std::string tip,bool angle):Character(id, point, PATH_CHARACTERS + tip)
{
	setInversionX(true);
}