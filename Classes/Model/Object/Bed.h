#ifndef BED_H__
#define BED_H__

#include "Model/Cell/TileCell.h"


class Bed:public TileCell
{
private:
public:
	Bed(PPoint point, //���������
		bool rotate // ������� true=l=������, false=r=�������
		);

};
#endif // BED_H__