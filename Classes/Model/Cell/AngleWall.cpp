#include "AngleWall.h"

AngleWall::AngleWall(PPoint* point, std::string tip, int tipAngle, bool show):Cell(point)
{
	
	if(show) setSize(100, 204); else setSize(100, 64);

	if(tipAngle == 4)
	{
		tipAngle = 2;
		setInversionX(true);
	}

	char tipAngle_str[25];
	_itoa(tipAngle,tipAngle_str,10);

	std::string path = PATH_WALLS + tip + tipAngle_str;

	if(!show) path+= "_s";

	createSprite(path);
}