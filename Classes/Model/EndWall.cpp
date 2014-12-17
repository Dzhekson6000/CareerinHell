#include "EndWall.h"

EndWall::EndWall(PPoint* point, std::string tip, int tipEnd, bool show):Cell(point)
{
	
	if(show) setDimensions(100, 204); else setDimensions(100, 64);

	if(tipEnd == 1)
	{
		tipEnd = 2;
		setInversionX(true);
	}else
	if(tipEnd == 3)
	{
		tipEnd = 4;
		setInversionX(true);
	}

	char tipEnd_str[25];
	_itoa(tipEnd,tipEnd_str,10);

	std::string path = "img/walls/" + tip + "_e" + tipEnd_str;

	if(!show) path+= "_s";

	createSprite(path);
}