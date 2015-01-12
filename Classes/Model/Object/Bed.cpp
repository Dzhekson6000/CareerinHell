#include "Bed.h"

Bed::Bed(PPoint* point, bool rotate):Cell(point)
{
	setInversionX(!rotate);
	setSize(143, 114);
	if(!rotate)
	{
		setCenter(25, 57);
	} else {
		setCenter(-25, 57);
	}
	std::string path = PATH_OBJECT "bed";

	createSprite(path);
}