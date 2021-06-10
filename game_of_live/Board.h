#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include <map>
#include "CellsStateStatistic.h"
#include <mutex>

class Board
{
public:
	Board();
	Board(int size);

	int size;

	mutable std::vector <CellsStateStatistic> StateStatisticVector;

	mutable std::mutex printMutex;

	mutable std::mutex multiThreadMutex;

	mutable std::vector <std::thread> threadVector;

	mutable std::vector <std::vector<Cell>> boardPtr;

	void initAliveCells();

	void initCellStats();

	void incrementStateObjectByState(short) const;

	void clearCellStats() const;

	void createBoard();

	void printBoard() const;

	void printCellAmountByAge() const;

	void syncStateOfCellBoards() const;

	void calcElementAmountByAge() const;

	void sortStateStatisticVector() const;

	void calcAndPrintBoardCellStatists() const;
};
