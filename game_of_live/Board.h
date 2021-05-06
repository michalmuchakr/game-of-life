#pragma once
#include <vector>
#include <iostream>
#include "Cell.h"

template <class T, class U>
class Board
{
public:
	Board(T aliveCellMark, U deadCellMark, int size);
	T aliveCellMark;
	U deadCellMark;

	int size;
	std::vector<std::vector<Cell>> boardPtr;

	void printBoard(T alive, U dead);
	void syncStateOfCellBoards();
};

template<class T, class U>
inline Board<T, U>::Board(T aliveCellMark, U deadCellMark, int size)
{
}

template<class T, class U>
inline void Board<T, U>::printBoard(T alive, U dead)
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (this->boardPtr[i][j].isAlife) {
				std::cout << alive;
			}
			else {
				std::cout << dead;
			}
			std::cout << " ";
		}
		std::cout << std::endl;

	}
}

template<class T, class U>
inline void Board<T, U>::syncStateOfCellBoards()
{
}
