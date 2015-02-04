#include "Altar.h"

Altar::Altar(PPoint* point, bool rotate):TileCell()
{
	std::string path1 = PATH_OBJECT "Altar";
	setPosition(point);
	addCell(path1, !rotate, false);
}