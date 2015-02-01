#include "Pathfinding.h"

void Pathfinder::find(PPoint* point, Character* character, PMap* map)
{
	character->clearPath();
	int count = 0;
	int step = 2;

	map->_passageWays[point->getXCell()][point->getYCell()] = 1;

	while (count < 40) {
		for (int row = 0; row < map->getWidth(); row++) {
			for (int column = 0; column < map->getHeight(); column++) {
				if (map->_passageWays[row][column] == step - 1) {
					if (row > 1) {
						if (map->_passageWays[row - 1][column] == 0) {
							map->_passageWays[row - 1][column] = step;
						}
					}
					if (row < map->getWidth() - 1) {
						if (map->_passageWays[row + 1][column] == 0) {
							map->_passageWays[row + 1][column] = step;
						}
					}
					if (column > 1) {
						if (map->_passageWays[row][column - 1] == 0) {
							map->_passageWays[row][column - 1] = step;
						}
					}
					if (column < map->getHeight() - 1) {
						if (map->_passageWays[row][column + 1] == 0) {
							map->_passageWays[row][column + 1] = step;
						}
					}
				}
			}
		}
		step++;
		count++;
	}
	PPoint* bufferPoint = new PPoint();
	bufferPoint->setXCell((int)(character->getPPosition()->getXOriginal()/50));
	bufferPoint->setYCell((int)(character->getPPosition()->getXOriginal()/50));
	int currentStep = map->_passageWays[bufferPoint->getXCell()][bufferPoint->getYCell()];

	Path path;
	CCLOG("current step=%i", currentStep);
	while(currentStep != 0) {
		if (map->_passageWays[bufferPoint->getXCell() - 1][bufferPoint->getYCell()] < currentStep + 1) {
			bufferPoint->setXCell(bufferPoint->getXCell() - 1);
			path.push_back(bufferPoint);
		}
		if (map->_passageWays[bufferPoint->getXCell() + 1][bufferPoint->getYCell()] < currentStep + 1) {
			bufferPoint->setXCell(bufferPoint->getXCell() + 1);
			path.push_back(bufferPoint);
		}
		if (map->_passageWays[bufferPoint->getXCell()][bufferPoint->getYCell() - 1] < currentStep + 1) {
			bufferPoint->setYCell(bufferPoint->getYCell() - 1);
			path.push_back(bufferPoint);
		}
		if (map->_passageWays[bufferPoint->getXCell()][bufferPoint->getYCell() + 1] < currentStep + 1) {
			bufferPoint->setYCell(bufferPoint->getYCell() + 1);
			path.push_back(bufferPoint);
		}
		currentStep--;
	}

	for(auto it = path.begin(); it != path.end(); ++it) {
		CCLOG("x=%i y=%i", (*it)->getXCell(), (*it)->getYCell());
	}

	if(!path.empty()) {
		character->setPath(path);
	}
}
