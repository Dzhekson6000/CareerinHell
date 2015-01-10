#include "Wall.h"

Wall::Wall(PPoint* point, std::string tip, bool rotate, bool show):Cell(point)
{
	setInversionX(!rotate);
	if(show) setSize(100, 204); else setSize(100, 64);

	std::string path = PATH_WALLS + tip;
	if(!show) path+= "_s";

	createSprite(path);
}