#include "AngleWall.h"

AngleWall::AngleWall(PPoint point, std::string tip, int tipAngle, bool show):TileCell()
{
	bool inversionX = false;
	if(tipAngle == 4)
	{
		tipAngle = 2;
		inversionX = true;
	}

	char tipAngle_str[25] = {0};
	sprintf(tipAngle_str, "%d", tipAngle);
	std::string path = PATH_WALLS + tip + tipAngle_str;
	if(!show) path+= "_s";

	setPosition(point);
	addCell(path, inversionX, false);
}