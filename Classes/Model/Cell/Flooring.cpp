#include "Flooring.h"

Flooring::Flooring(PPoint* point, std::string tip):Cell(point)
{
	_order = -1;
	setDimensions(100, 52);

	std::string path = "img/flooring/" + tip;
	createSprite(path);
}