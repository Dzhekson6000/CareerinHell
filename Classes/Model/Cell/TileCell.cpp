#include "TileCell.h"

TileCell::TileCell()
{
	_sizeX = 1;
	_sizeY = 1;
	_order = 0;
	_passage = 255;
	_point = PPoint(0,0);
}

void TileCell::addCell(std::string textureName, bool inversionX, bool inversionY)
{
	addCell(PPoint(0, 0), textureName, inversionX, inversionY);
}

void TileCell::addCell(PPoint point, std::string textureName, bool inversionX, bool inversionY)
{
	Cell cell = Cell(point, &_point, textureName, inversionX, inversionY);
	cell.setOrder(_order);
	cell.setPassage(_passage);
	_cells.push_back(cell);
}


void TileCell::setPosition(PPoint point){
	_point = point;
	for(auto cell:_cells)cell.setPositionTile(&_point);
}

void TileCell::setPassage(int passage)
{
	_passage = passage;
	for(auto cell:_cells)cell.setPassage(passage);
}

void TileCell::setOrder(int order)
{
	_order = order;
	for(auto cell:_cells)cell.setOrder(_order);
}

PPoint* TileCell::getPosition()
{
	return &_point;
}

std::vector <Cell>* TileCell::getCells()
{
	return &(_cells);
}