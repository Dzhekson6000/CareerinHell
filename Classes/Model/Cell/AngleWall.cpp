#include "AngleWall.h"

AngleWall::AngleWall(PPoint* point, std::string tip, int tipAngle, bool show):Cell(point)
{
	
	if(show) setDimensions(100, 204); else setDimensions(100, 64);

	if(tipAngle == 4)
	{
		tipAngle = 2;
		setInversionX(true);
	}

	char tipAngle_str[25];
	_itoa(tipAngle,tipAngle_str,10);

	std::string path = "img/walls/" + tip + tipAngle_str;

	if(!show) path+= "_s";

	createSprite(path);
}