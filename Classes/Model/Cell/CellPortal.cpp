#include "CellPortal.h"

CellPortal::CellPortal(PPoint* point, std::string tip, bool rotate):Cell(point)
{
	setInversionX(!rotate);
	setSize(100, 204);

	std::string path = PATH_PORTALS + tip;

	createSprite(path);

}

void CellPortal::click()
{
	CCLOG("Portal warp =)");
}