#pragma once
#include <vector>
#include "Cell.h"
#include "Board.h"
#include <iostream>

Board::Board()
{
}

Board::Board(int size) : size(size) {
	this->createBoard();
	this->initAliveCells();
}

void Board::test()
{
	std::cout << "Here!" << std::endl;
}

void Board::initAliveCells()
{
	//this->boardPtr[1][0].isAlife = true;
	//this->boardPtr[1][2].isAlife = true;
	//this->boardPtr[2][1].isAlife = true;
	//this->boardPtr[2][2].isAlife = true;
	//this->boardPtr[3][1].isAlife = true;

	this->boardPtr[1][0].cellStatus = 0;
	this->boardPtr[1][2].cellStatus = 0;
	this->boardPtr[2][1].cellStatus = 0;
	this->boardPtr[2][2].cellStatus = 0;
	this->boardPtr[3][1].cellStatus = 0;
}

void Board::createBoard()
{
	this->boardPtr.resize(this->size);
	for (int i = 0; i < this->size; i++) {
		this->boardPtr[i].resize(this->size);
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i].push_back(Cell());
		}
	}
}

void Board::printBoard() const {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			std::cout << boardPtr[i][j].checkCellStatus();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Board::syncStateOfCellBoards() const
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i][j].cellStatus = this->boardPtr[i][j].nextStatus;
		}
	}
}
