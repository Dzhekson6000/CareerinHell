#ifndef BOAT_H__
#define BOAT_H__

#include "Character.h"


class Boat:public Character
{
private:
public:
	Boat(PPoint* point, //начальное положение
		std::string tip, //тип существа
		bool angle // поворот true=l=налево, false=r=направо
		);

	void setPosition(PPoint* point);

};
#endif // BOAT_H__