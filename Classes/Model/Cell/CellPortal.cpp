#include "CellPortal.h"

CellPortal::CellPortal(PPoint* point, std::string tip, bool rotate):TileCell()
{
	std::string path = PATH_PORTALS + tip;
	setPosition(point);
	setPassage(0);
	addCell(path, !rotate, false);
}

void CellPortal::click(InterfaceGame* interfaceGame)
{
	interfaceGame->createPortalBox();
}