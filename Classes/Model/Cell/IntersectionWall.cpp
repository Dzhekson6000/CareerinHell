#include "IntersectionWall.h"

IntersectionWall::IntersectionWall(PPoint* point, std::string tip, int tipIntersection, bool show):Cell(point)
{
	
	if(show) setDimensions(100, 204); else setDimensions(100, 64);

	std::string path = "img/walls/" + tip + "_i";

	if(tipIntersection == 1)
	{
		tipIntersection = 2;
		setInversionX(true);
	} else
	if(tipIntersection == 4)
	{
		tipIntersection = 3;
		setInversionX(true);
	}

	if(tipIntersection != 0){
		char tipIntersection_str[25];
		_itoa(tipIntersection,tipIntersection_str,10);
		path += tipIntersection_str;
	}

	if(!show) path+= "_s";

	createSprite(path);
}