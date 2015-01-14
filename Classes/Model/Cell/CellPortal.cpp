#include "CellPortal.h"

CellPortal::CellPortal(PPoint* point, std::string tip, bool rotate):TileCell()
{
	std::string path = PATH_PORTALS + tip;
	setPosition(point);
	addCell(path, !rotate, false);
}

void CellPortal::click()
{
	CCLOG("Portal warp =)");
}