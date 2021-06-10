#pragma once

#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Moore.h"
#include "CellsStateStatistic.h"

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

    mutable int anountOfUserProvideBoardSize;

    mutable int anountOfUserProvideBoardSizeLimit;

    int amountOfIterations;

    void initUserBoardSize() const;

    void initBoard() const;

    void initThreadVector() const;

    void getUserSizeOfBoard() const;

    void handleBoardError(std::string) const;

    void handleAmountOfTryError(std::string) const;

    void processBoard() const;

    void incrementIfSiblingIsAlive(const Cell&, int&) const;

    void ageUpAliveCell() const;

    constexpr int getAmountOfLiveSiblings(int, int) const;

    int determineIfDeadOrAlive(int, short) const;

    short checkInitiallyAlive(int, short) const;

    short checkInitiallyDead(int) const;

    void calcAndPrintBoardStatistic() const;
};
