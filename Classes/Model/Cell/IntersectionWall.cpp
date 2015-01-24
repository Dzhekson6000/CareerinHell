#include "IntersectionWall.h"

IntersectionWall::IntersectionWall(PPoint* point, std::string tip, int tipIntersection, bool show):TileCell()
{
	bool inversionX = false;
	std::string path = PATH_WALLS + tip + "_i";

	if(tipIntersection == 1)
	{
		tipIntersection = 2;
		inversionX = true;
	} else
	if(tipIntersection == 4)
	{
		tipIntersection = 3;
		inversionX = true;
	}

	if(tipIntersection != 0){
		char tipIntersection_str[25] = {0};
		sprintf(tipIntersection_str, "%d", tipIntersection);
		path += tipIntersection_str;
	}

	if(!show) path+= "_s";

	setPosition(point);
	addCell(path, inversionX, false);
}