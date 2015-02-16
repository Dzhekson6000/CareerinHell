#ifndef ANGLE_WALL_H__
#define ANGLE_WALL_H__

#include "TileCell.h"

class AngleWall:public TileCell
{
private:
public:
	AngleWall(PPoint point, //положение
		std::string tip, //тип
		int tipAngle, // поворот true=l=налево, false=r=направо
		bool show //скрыть стену
		);

};
#endif // ANGLE_WALL_H__