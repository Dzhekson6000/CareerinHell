#ifndef ANGLE_WALL_H__
#define ANGLE_WALL_H__

#include "Cell.h"


class AngleWall:public Cell
{
private:
public:
	AngleWall(PPoint* point, //���������
		std::string tip, //���
		int tipAngle, // ������� true=l=������, false=r=�������
		bool show //������ �����
		);

};
#endif // WALL_H__