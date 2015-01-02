#ifndef END_WALL_H__
#define END_WALL_H__

#include "Cell.h"


class EndWall:public Cell
{
private:
public:
	EndWall(PPoint* point, //положение
		std::string tip, //тип
		int tipEnd, // поворот true=l=налево, false=r=направо
		bool show //скрыть стену
		);

};
#endif // END_WALL_H__