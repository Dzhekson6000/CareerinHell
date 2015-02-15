#include "Boat.h"

Boat::Boat(int id, Level* level, PPoint* point,std::string tip,bool angle):Character(id, level, point, PATH_CHARACTERS + tip)
{
	setInversionX(true);
}