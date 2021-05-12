#pragma once
#include "Cell.h"
#include "Board.h"

class Moore
{
public:
	Moore();

	void incrementIfSiblingIsAlife(const Cell & cellToCheck, int& amountOfLiveSiblings) const;

	int getAmmountOfLiveSiblings(int y, int x, const Board<> * board, int size);
};
