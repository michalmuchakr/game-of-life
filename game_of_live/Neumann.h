#pragma once
#include "Cell.h"
#include "Board.h"

class Neumann
{
public:
    Neumann();

    void incrementIfSiblingIsAlive(const Cell & cellToCheck, int& amountOfLiveSiblings) const;

    int getAmountOfLiveSiblings(int y, int x, const Board * board, int size);

    bool checkNeighborhoodForNeumann(int x, int y);
};
