#ifndef BED_H__
#define BED_H__

#include "../Cell/Cell.h"


class Bed:public Cell
{
private:
public:
	Bed(PPoint* point, //���������
		bool rotate // ������� true=l=������, false=r=�������
		);

};
#endif // BED_H__