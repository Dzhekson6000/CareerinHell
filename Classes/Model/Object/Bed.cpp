#include "Bed.h"

Bed::Bed(PPoint* point, bool rotate):TileCell()
{
	std::string path1 = PATH_OBJECT "bed1";
	std::string path2 = PATH_OBJECT "bed2";

	setPosition(point);
	addCell(path1, !rotate, false);
	addCell(new PPoint(1, 0), path2, !rotate, false);
}