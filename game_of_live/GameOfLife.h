#pragma once

#include <vector>
#include "Cell.h"
#include <iostream>

template<class T = char, class U = char>
class GameOfLife {
public:

    GameOfLife(T alive, U dead, int size);
    std::vector <std::vector<Cell>> boardPtr;
    int size;

    T alive;
    U dead;

    void printBoard();

    void createBoard();

    void processBoard();

    void syncStateOfCellBoards();

    int getAmmountOfLiveSiblings(int y, int x);

    int determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead);

    int checkInitialyAlive(int amountOfLiveSiblings);

    int checkInitialyDead(int amountOfLiveSiblings);
};