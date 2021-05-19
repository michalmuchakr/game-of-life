#pragma once
#include <vector>
#include "Cell.h"
#include "Board.h"
#include <iostream>
#include <map>

Board::Board() : size(0)
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

void Board::printCellAmountByAge(std::map<short, int> elementsByAgeMap) const
{
	std::cout << "----------------------------------------------" << std::endl;
	for (auto const& [key, val] : elementsByAgeMap)
	{
		std::cout 
			<< Cell::getStateNameByValue(key)
			<< ": \t"
			<< val
			<< std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
}

void Board::syncStateOfCellBoards() const
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i][j].cellStatus = this->boardPtr[i][j].nextStatus;
		}
	}
}

std::map<short, int> Board::calcElementAmountByAge() const
{
	std::map<short, int> elementsByAgeMap;

	// init null state of each possible state of cell
	// Cell::DEAD -> last of state at enum is ammount of possible states
	for (int i = 0; i < Cell::DEAD; i++) {
		elementsByAgeMap[i] = 0;
	}

	auto ageUpParticularCell = [&](short state) {
		elementsByAgeMap[state] = elementsByAgeMap[state] + 1;
	};

	// itterate over board
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			ageUpParticularCell(this->boardPtr[i][j].cellStatus);
		}
	}

	return elementsByAgeMap;
}
