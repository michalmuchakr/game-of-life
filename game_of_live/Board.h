#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>

template <class T = char, class U = char>
class Board
{
public:
	Board();
	Board(T aliveCellMark, U deadCellMark, int size);

	T aliveCellMark;
	U deadCellMark;
	int size;
	mutable std::vector<std::vector<Cell>> boardPtr;

	void initAliveCells();

	void createBoard();
	void printBoard() const;
	void syncStateOfCellBoards() const;
};

template<class T, class U>
inline Board<T, U>::Board()
{
}

template<class T, class U>
inline Board<T, U>::Board(T aliveCellMark, U deadCellMark, int size):
	aliveCellMark(aliveCellMark), deadCellMark(deadCellMark), size(size) {
	this->createBoard();
	this->initAliveCells();
}

template<class T, class U>
inline void Board<T, U>::initAliveCells()
{
	this->boardPtr[1][0].isAlife = true;
	this->boardPtr[1][2].isAlife = true;
	this->boardPtr[2][1].isAlife = true;
	this->boardPtr[2][2].isAlife = true;
	this->boardPtr[3][1].isAlife = true;
}

template<class T, class U>
inline void Board<T, U>::createBoard()
{
	this->boardPtr.resize(this->size);
	for (int i = 0; i < this->size; i++) {
		this->boardPtr[i].resize(this->size);
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i].push_back(Cell());
		}
	}
}

template<class T, class U>
inline void Board<T, U>::printBoard() const {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (this->boardPtr[i][j].isAlife) {
				std::cout << this->aliveCellMark;
			}
			else {
				std::cout << this->deadCellMark;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

template<class T, class U>
inline void Board<T, U>::syncStateOfCellBoards() const {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->boardPtr[i][j].isAlife = this->boardPtr[i][j].willBeAlive;
        }
    }
}
