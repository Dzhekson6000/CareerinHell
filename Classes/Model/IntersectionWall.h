#ifndef INTERSECTION_WALL_H__
#define INTERSECTION_WALL_H__

#include "Cell.h"


class IntersectionWall:public Cell
{
private:
public:
	IntersectionWall(PPoint* point, //положение
		std::string tip, //тип
		int tipIntersection, // поворот true=l=налево, false=r=направо
		bool show //скрыть стену
		);

};
#endif // INTERSECTION_WALL_H__