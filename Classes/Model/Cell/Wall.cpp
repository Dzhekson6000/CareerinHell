#include "Wall.h"

Wall::Wall(PPoint* point, std::string tip, bool rotate, bool show):Cell(point)
{
	setInversionX(!rotate);
	if(show) setDimensions(100, 204); else setDimensions(100, 64);

	std::string path = "img/walls/" + tip;
	if(!show) path+= "_s";

	createSprite(path);
}