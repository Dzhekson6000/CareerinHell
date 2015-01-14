#ifndef WALL_H__
#define WALL_H__

#include "TileCell.h"


class Wall:public TileCell
{
private:
public:
	Wall(PPoint* point, //положение
		std::string tip, //тип
		bool rotate, // поворот true=l=налево, false=r=направо
		bool show //скрыть стену
		);

};
#endif // WALL_H__