#ifndef INTERSECTION_WALL_H__
#define INTERSECTION_WALL_H__

#include "Cell.h"


class IntersectionWall:public Cell
{
private:
public:
	IntersectionWall(PPoint* point, //���������
		std::string tip, //���
		int tipIntersection, // ������� true=l=������, false=r=�������
		bool show //������ �����
		);

};
#endif // INTERSECTION_WALL_H__