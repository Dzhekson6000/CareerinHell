#ifndef ANGLE_WALL_H__
#define ANGLE_WALL_H__

#include "Cell.h"


class AngleWall:public Cell
{
private:
public:
	AngleWall(PPoint* point, //положение
		std::string tip, //тип
		int tipAngle, // поворот true=l=налево, false=r=направо
		bool show //скрыть стену
		);

};
#endif // WALL_H__