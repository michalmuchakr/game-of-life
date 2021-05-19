#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include <map>

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
	void printCellAmountByAge(std::map<short, int> elementsByAgeMap) const;
	void syncStateOfCellBoards() const;

	std::map<short, int> calcElementAmountByAge() const;
};
