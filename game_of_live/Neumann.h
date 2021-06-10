#pragma once
#include "Cell.h"
#include "Board.h"

class Neumann
{
public:
    Neumann();

    void incrementIfSiblingIsAlive(const Cell &, int&) const;

    int getAmountOfLiveSiblings(int, int, const Board *, int);

    bool checkNeighborhoodForNeumann(int, int);
};
