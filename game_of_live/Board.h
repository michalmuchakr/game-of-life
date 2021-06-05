#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include <map>
#include "CellsStateStatistic.h"

class Board
{
public:
	Board();
	Board(int size);

	int size;

	mutable std::vector<std::vector<Cell>> boardPtr;

	mutable std::vector <CellsStateStatistic> StateStatisticVector;

	void initAliveCells();
	void initCellStats();
	void incrementStateObjectByState(short state) const;
	void clearCellStats() const;
	void createBoard();
	void printBoard() const;
	void printCellAmountByAge() const;
	void syncStateOfCellBoards() const;
	void calcElementAmountByAge() const;
	void sortStateStatisticVector() const;
	void calcAndPrintBoardCellStatists() const;
};
