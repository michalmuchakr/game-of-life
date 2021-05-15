#pragma once

#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Moore.h"

template<class S = Moore>
class GameOfLife {
public:
    GameOfLife();

    GameOfLife(S* siblings, int size);

    void start() const;

    S* siblings;

    const Board* board;

    const int size;

    void processBoard() const;

    void incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const;

    constexpr int getAmountOfLiveSiblings(int y, int x) const;

    int determineIfDeadOrAlive(int amountOfLiveSiblings, short initiallyAliveOrDead) const;

    short checkInitiallyAlive(int amountOfLiveSiblings) const;

    short checkInitiallyDead(int amountOfLiveSiblings) const;
};