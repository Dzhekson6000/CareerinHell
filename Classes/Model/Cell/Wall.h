#ifndef WALL_H__
#define WALL_H__

#include "TileCell.h"


class Wall:public TileCell
{
private:
public:
	Wall(PPoint* point, //���������
		std::string tip, //���
		bool rotate, // ������� true=l=������, false=r=�������
		bool show //������ �����
		);

};
#endif // WALL_H__