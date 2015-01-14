#include "EndWall.h"

EndWall::EndWall(PPoint* point, std::string tip, int tipEnd, bool show):TileCell()
{
	bool inversionX = false;
	if(tipEnd == 1)
	{
		tipEnd = 2;
		inversionX = true;
	}else
	if(tipEnd == 3)
	{
		tipEnd = 4;
		inversionX = true;
	}

	char tipEnd_str[25];
	_itoa(tipEnd,tipEnd_str,10);

	std::string path = PATH_WALLS + tip + "_e" + tipEnd_str;

	if(!show) path+= "_s";

	setPosition(point);
	addCell(path, inversionX, false);
}