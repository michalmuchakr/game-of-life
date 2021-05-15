#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>

class Board
{
public:
	Board();
	Board(int size);

	void test();

	int size;
	mutable std::vector<std::vector<Cell>> boardPtr;

	void initAliveCells();

	void createBoard();
	void printBoard() const;
	void syncStateOfCellBoards() const;
};
