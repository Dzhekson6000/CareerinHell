#include "Flooring.h"

Flooring::Flooring(PPoint point, std::string tip):TileCell()
{
	std::string path = PATH_FLOOR + tip;
	setPassage(0);
	setOrder(-2);
	setPosition(point);
	addCell(path, false, false);
}
