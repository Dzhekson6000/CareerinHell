#ifndef BOAT_H__
#define BOAT_H__

#include "Character.h"


class Boat:public Character
{
private:
public:
	Boat(int id,
		Level* level,
		PPoint* point,
		std::string tip,
		bool angle
		);

	void setPosition(PPoint* point);

};
#endif // BOAT_H__