#pragma once

#include <vector>
#include "Cell.h"
#include <iostream>

template<class T, class U>
class Board {
public:
    Board(T aliveCellMark, U deadCellMark, int size);

    T aliveCellMark;
    U deadCellMark;
    int size;
    std::vector <std::vector<Cell>> boardPtr;

    void printBoard();

    void syncStateOfCellBoards();
};