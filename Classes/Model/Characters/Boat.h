#ifndef BOAT_H__
#define BOAT_H__

#include "Character.h"


class Boat:public Character
{
private:
public:
	Boat(PPoint* point, //��������� ���������
		std::string tip, //��� ��������
		bool angle // ������� true=l=������, false=r=�������
		);

	void setPosition(PPoint* point);

};
#endif // BOAT_H__