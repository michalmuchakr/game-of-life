#include <iostream>
#include "GameOfLife.h"

GameOfLife::GameOfLife(int size)
{
	this->size = size;
	this->board = nullptr;
}

void GameOfLife::start()
{
}

void GameOfLife::createBoard()
{
	this->board = new int** [this->size];
	for (int i = 0; i < this->size; i++) {
		board[i] = new int* [this->size];
		for (int j = 0; j < this->size; j++) {
			board[i][j] = new int[2];
		}
	}
}

void GameOfLife::nullBoard()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->board[i][j][0] = 0;
			this->board[i][j][1] = 0;
		}
	}
}

void GameOfLife::printBoard()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (this->board[i][j][0] == 0) {
				std::cout << ".";
			}
			else {
				std::cout << "X";
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void GameOfLife::processBoard()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			int amountOfLiveSiblings = getAmmountOfLiveSiblings(i, j);
			this->board[i][j][1] = determineIfDeadOrAlife(amountOfLiveSiblings, this->board[i][j][0]);
		}
	}
}

void GameOfLife::syncStateOfCellBoards()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->board[i][j][0] = this->board[i][j][1];
		}
	}
}

int GameOfLife::getAmmountOfLiveSiblings(int y, int x)
{
	int amountOfLiveSiblings = 0;

	// process vertical siblings
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {

			// same field under investigation
			if (j == x && i == y) {
				continue;
			}

			// out of board range
			if (i < 0 || i > this->size - 1 || j < 0 || j > this->size - 1) {
				continue;
			}

			if (this->board[i][j][0] == 1) {
				amountOfLiveSiblings++;
			}
		}
	}

	return amountOfLiveSiblings;
}

int GameOfLife::determineIfDeadOrAlife(int amountOfLiveSiblings, int initialyAliveOrDead)
{
	int resultState;

	if (initialyAliveOrDead) {
		resultState = checkInitialyAlive(amountOfLiveSiblings);
	}
	else {
		resultState = checkInitialyDead(amountOfLiveSiblings);
	}

	return resultState;
}

int GameOfLife::checkInitialyAlive(int amountOfLiveSiblings)
{
	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	// Any live cell with more than three live neighbours dies, as if by overpopulation.
	int resultState = 0;

	// Any live cell with two or three live neighbours lives on to the next generation.
	if (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) {
		resultState = 1;
	}

	return resultState;
}

int GameOfLife::checkInitialyDead(int amountOfLiveSiblings)
{
	// All other dead cells stay dead.
	int resultState = 0;

	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	if (amountOfLiveSiblings == 3) {
		resultState = 1;
	}

	return resultState;
}
