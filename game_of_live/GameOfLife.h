#pragma once

#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Moore.h"

template<class T = char, class U = char, class S = Moore>
class GameOfLife {
public:
    GameOfLife();

    GameOfLife(T alive, U dead, S * sibl, int size);

    void start() const;
    
    S * siblings;

    const Board<T, U> * board;

    const int size;

    void processBoard() const;

    void incrementIfSiblingIsAlife(const Cell& cellToCheck, int& amountOfLiveSiblings) const;

    constexpr int getAmmountOfLiveSiblings(int y, int x) const;

    int determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead) const;

    int checkInitialyAlive(int amountOfLiveSiblings) const;

    int checkInitialyDead(int amountOfLiveSiblings) const;
};