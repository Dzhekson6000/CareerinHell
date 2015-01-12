#ifndef BED_H__
#define BED_H__

#include "../Cell/Cell.h"


class Bed:public Cell
{
private:
public:
	Bed(PPoint* point, //положение
		bool rotate // поворот true=l=налево, false=r=направо
		);

};
#endif // BED_H__