#ifndef ANGLE_WALL_H__
#define ANGLE_WALL_H__

#include "TileCell.h"

class AngleWall:public TileCell
{
private:
public:
	AngleWall(PPoint point, //���������
		std::string tip, //���
		int tipAngle, // ������� true=l=������, false=r=�������
		bool show //������ �����
		);

};
#endif // ANGLE_WALL_H__