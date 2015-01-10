#include "Flooring.h"

Flooring::Flooring(PPoint* point, std::string tip):Cell(point)
{
	_order = -1;
	setSize(100, 52);

	std::string path = PATH_FLOOR + tip;
	createSprite(path);
}