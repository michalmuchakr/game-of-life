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

    GameOfLife(S* siblings);

    void start() const;

    S* siblings;

    // Since the pointer is mutable, it can be modified in a const method
    // The value it points to is const, and cannot be modified through that pointer.
    mutable const Board* board;

    mutable int size;

    void initUserBoardSize() const;

    void initBoard() const;

    void getUserSizeOfBoard() const;

    void handleBoardError(std::string errorMsg) const;

    void processBoard() const;

    void incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const;

    void ageUpAliveCell() const;

    constexpr int getAmountOfLiveSiblings(int y, int x) const;

    int determineIfDeadOrAlive(int amountOfLiveSiblings, short initiallyAliveOrDead) const;

    short checkInitiallyAlive(int amountOfLiveSiblings, short initiallyAliveOrDead) const;

    short checkInitiallyDead(int amountOfLiveSiblings) const;
};