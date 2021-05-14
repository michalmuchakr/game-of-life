#pragma once

#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Moore.h"

template<class S = Moore, class T = char, class U = char>
class GameOfLife {
public:
    GameOfLife();

    GameOfLife(S* siblings, T alive, U dead, int size);

    void start() const;

    S* siblings;

    const Board<T, U>* board;

    const int size;

    void processBoard() const;

    void incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const;

    constexpr int getAmountOfLiveSiblings(int y, int x) const;

    int determineIfDeadOrAlive(int amountOfLiveSiblings, bool initiallyAliveOrDead) const;

    int checkInitiallyAlive(int amountOfLiveSiblings) const;

    int checkInitiallyDead(int amountOfLiveSiblings) const;
};