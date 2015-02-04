#ifndef ALTAR_H__
#define ALTAR_H__

#include "Model/Cell/TileCell.h"


class Altar:public TileCell
{
private:
public:
	Altar(PPoint* point, //положение
		bool rotate // поворот true=l=налево, false=r=направо
		);

};
#endif // ALTAR_H__