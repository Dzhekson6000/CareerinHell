#ifndef CELLPORTAL_H__
#define CELLPORTAL_H__

#include "TileCell.h"


class CellPortal:public TileCell
{
private:
public:
	CellPortal(PPoint point,
		std::string tip,
		bool rotate
		);
	void click(InterfaceGame* interfaceGame);

};
#endif // CELLPORTAL_H__