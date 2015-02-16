#ifndef ALTAR_H__
#define ALTAR_H__

#include "Model/Cell/TileCell.h"


class Altar:public TileCell
{
private:
public:
	Altar(PPoint point,
		bool rotate
		);
	void click(InterfaceGame* interfaceGame);

};
#endif // ALTAR_H__