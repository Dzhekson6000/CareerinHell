#ifndef END_WALL_H__
#define END_WALL_H__

#include "Cell.h"


class EndWall:public Cell
{
private:
public:
	EndWall(PPoint* point, //���������
		std::string tip, //���
		int tipEnd, // ������� true=l=������, false=r=�������
		bool show //������ �����
		);

};
#endif // END_WALL_H__