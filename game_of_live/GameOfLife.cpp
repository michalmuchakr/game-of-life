#include <iostream>
#include "GameOfLife.h"

GameOfLife::GameOfLife(int size)
{
	this->size = size;
}

void GameOfLife::createBoard()
{
	this->boardPtr = std::make_unique<std::unique_ptr<std::unique_ptr<int[]>[]>[]>(this->size);

	for (int k = 0; k < this->size; k++)
	{
		boardPtr[k] = std::make_unique<std::unique_ptr<int[]>[]>(this->size);
		for (int i = 0; i < this->size; i++) {
			boardPtr[k][i] = std::make_unique<int[]>(this->size);
			for (int j = 0; j < 2; j++) {
				boardPtr[k][i][j] = 0;
			}
		}
	}
}

void GameOfLife::printBoard()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (this->boardPtr[i][j][0] == 0) {
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
			this->boardPtr[i][j][1] = determineIfDeadOrAlife(amountOfLiveSiblings, this->boardPtr[i][j][0]);
		}
	}
}

void GameOfLife::syncStateOfCellBoards()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i][j][0] = this->boardPtr[i][j][1];
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

			// out of boardPtr range
			if (i < 0 || i > this->size - 1 || j < 0 || j > this->size - 1) {
				continue;
			}

			if (this->boardPtr[i][j][0] == 1) {
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
