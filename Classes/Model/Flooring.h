#ifndef FLOORING_H__
#define FLOORING_H__

#include "Cell.h"


class Flooring:public Cell
{
private:
public:
	Flooring(PPoint* point, //положение
		std::string tip //тип
		);

};
#endif // FLOORING_H__