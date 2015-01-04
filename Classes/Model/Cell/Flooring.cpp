#include "Flooring.h"

Flooring::Flooring(PPoint* point, std::string tip):Cell(point)
{
	setDimensions(100, 52);

	std::string path = "img/flooring/" + tip;
	createSprite(path);
}