#pragma once

#include <vector>
#include "Cell.h"
#include "Board.h"
#include <iostream>

template<class T = char, class U = char>
class GameOfLife {
public:
    GameOfLife(T alive, U dead, int size);

    void start() const;
    
    const Board<T, U> * board;

    const int size;

    void processBoard() const;

    void incrementIfSiblingIsAlife(const Cell& cellToCheck, int& amountOfLiveSiblings) const;

    constexpr int getAmmountOfLiveSiblings(int y, int x) const;

    int determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead) const;

    int checkInitialyAlive(int amountOfLiveSiblings) const;

    int checkInitialyDead(int amountOfLiveSiblings) const;
};