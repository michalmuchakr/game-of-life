#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include "Cell.h"
#include "Board.h"
#include "CellsStateStatistic.h"
#include <thread>

Board::Board() : size(0)
{
}

Board::Board(int size) : size(size)
{
	this->createBoard();
	this->initAliveCells();
	this->initCellStats();
}

void Board::initAliveCells()
{
	this->boardPtr[1][0].cellStatus = 0;
	this->boardPtr[1][2].cellStatus = 0;
	this->boardPtr[2][1].cellStatus = 0;
	this->boardPtr[2][2].cellStatus = 0;
	this->boardPtr[3][1].cellStatus = 0;
}

void Board::initCellStats()
{
	for (int i = 0; i <= Cell::DEAD; i++) {
		this->StateStatisticVector.push_back(CellsStateStatistic(i));
	}
}

void Board::incrementStateObjectByState(short state) const
{
	std::vector<CellsStateStatistic>::iterator elementToUpdate = std::find_if(
		StateStatisticVector.begin(),
		StateStatisticVector.end(),
		[&](CellsStateStatistic CellsStateStat) {
			return CellsStateStat.cellId == state;
		}
	);

	multiThreadMutex.lock();
	
	(*elementToUpdate).amount += 1;

	multiThreadMutex.unlock();
}

void Board::clearCellStats() const
{
	for (int i = 0; i <= Cell::DEAD; i++)
	{
		this->StateStatisticVector[i].amount = 0;
	}
}

void Board::createBoard()
{
	this->boardPtr.resize(this->size);
	for (int i = 0; i < this->size; i++)
	{
		this->boardPtr[i].resize(this->size);
		for (int j = 0; j < this->size; j++)
		{
			this->boardPtr[i].push_back(Cell());
		}
	}
}

void Board::printBoard() const
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			std::cout << boardPtr[i][j].checkCellStatus();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Board::printCellAmountByAge() const
{
	std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i < this->StateStatisticVector.size(); i++)
	{
		std::cout << this->StateStatisticVector[i].cellName << ": \t" << this->StateStatisticVector[i].amount << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

void Board::syncStateOfCellBoards() const
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			this->boardPtr[i][j].cellStatus = this->boardPtr[i][j].nextStatus;
		}
	}
}

void call_from_thread(int tid)
{
    std::cout << "Launched by thread " << tid << std::endl;
}

void Board::calcElementAmountByAge() const
{
	std::mutex printMutex;

	auto calcElementAmountByAgeRow = [&](int rowIdx)
	{
		printMutex.lock();
		std::cout << "Thread with id: " << std::this_thread::get_id() << " calculate it's part." << std::endl;
		printMutex.unlock();

		for (int j = 0; j < this->size; j++)
		{
			incrementStateObjectByState(this->boardPtr[rowIdx][j].cellStatus);
		}
	};

	for (int i = 0; i < this->size; i++)
	{
		this->threadVector[i] = std::thread(calcElementAmountByAgeRow, i);
	}

	for (int i = 0; i < this->size; i++)
	{
		this->threadVector[i].join();
	}
}

void Board::sortStateStatisticVector() const
{
	std::sort(
		this->StateStatisticVector.begin(),
		this->StateStatisticVector.end(),
		std::greater<CellsStateStatistic>()
	);
}

void Board::calcAndPrintBoardCellStatists() const
{
	this->clearCellStats();
	this->calcElementAmountByAge();
	this->sortStateStatisticVector();
	this->printCellAmountByAge();
}
