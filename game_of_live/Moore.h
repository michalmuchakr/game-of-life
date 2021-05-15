#pragma once
#include "Cell.h"
#include "Board.h"

class Moore
{
public:
	Moore();

	void incrementIfSiblingIsAlive(const Cell & cellToCheck, int& amountOfLiveSiblings) const;

	int getAmountOfLiveSiblings(int y, int x, const Board * board, int size);
};
