#ifndef CELLPORTAL_H__
#define CELLPORTAL_H__

#include "TileCell.h"


class CellPortal:public TileCell
{
private:
public:
	CellPortal(PPoint* point, //положение
		std::string tip, //тип
		bool rotate // поворот true=l=налево, false=r=направо
		);
	void click();

};
#endif // CELLPORTAL_H__