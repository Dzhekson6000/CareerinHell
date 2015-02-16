#ifndef FLOORING_H__
#define FLOORING_H__

#include "TileCell.h"


class Flooring:public TileCell
{
private:
public:
	Flooring(PPoint point, //положение
		std::string tip //тип
		);

};
#endif // FLOORING_H__