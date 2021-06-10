#pragma once
#include "Cell.h"
#include "Board.h"

class Moore
{
public:
	Moore();

	void incrementIfSiblingIsAlive(const Cell &, int&) const;

	int getAmountOfLiveSiblings(int, int, const Board *, int);
};
