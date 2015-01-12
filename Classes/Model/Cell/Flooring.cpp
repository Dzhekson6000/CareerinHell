#include "Flooring.h"

Flooring::Flooring(PPoint* point, std::string tip):Cell(point)
{
	_passage = 0;
	_order = -1;
	setSize(100, 52);

	std::string path = PATH_FLOOR + tip;
	createSprite(path);
}