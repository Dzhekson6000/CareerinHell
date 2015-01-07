#include "CellPortal.h"

CellPortal::CellPortal(PPoint* point, std::string tip, bool rotate):Cell(point)
{
	setInversionX(!rotate);
	setDimensions(100, 204);

	std::string path = "img/portals/" + tip;

	createSprite(path);

}

void CellPortal::click()
{
	CCLOG("Portal warp =)");
}