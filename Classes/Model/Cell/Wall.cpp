#include "Wall.h"

Wall::Wall(PPoint* point, std::string tip, bool rotate, bool show):TileCell()
{
	std::string path = PATH_WALLS + tip;
	if(!show) path+= "_s";
	setPosition(point);
	addCell(path, !rotate, false);
}