#include <iostream>
#include <vector>
#include "GameOfLife.h"
#include "Cell.h"

GameOfLife::GameOfLife(int size): size(size)
{
}

void GameOfLife::createBoard()
{
	// Cell board
	boardPtr.resize(this->size);
	for (int d = 0; d < this->size; d++)
	{
		boardPtr[d].resize(this->size);
		for (int i = 0; i < this->size; i++) {
			// cells' prev and next state
			boardPtr[d].push_back(Cell());
		}
	}
}

void GameOfLife::processBoard()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			int amountOfLiveSiblings = getAmmountOfLiveSiblings(i, j);
			this->boardPtr[i][j].willBeAlive = determineIfDeadOrAlife(amountOfLiveSiblings, this->boardPtr[i][j].isAlife);
		}
	}
}

void GameOfLife::syncStateOfCellBoards()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->boardPtr[i][j].isAlife = this->boardPtr[i][j].willBeAlive;
		}
	}
}

//y
//| [ ][ ][ ]
//| [ ][X][ ]
//| [ ][ ][ ]
//------------- x
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

			if (this->boardPtr[i][j].isAlife) {
				amountOfLiveSiblings++;
			}
		}
	}

	return amountOfLiveSiblings;
}

int GameOfLife::determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead)
{
	if (initialyAliveOrDead) {
		return checkInitialyAlive(amountOfLiveSiblings);
	}
	else {
		return checkInitialyDead(amountOfLiveSiblings);
	}
}

int GameOfLife::checkInitialyAlive(int amountOfLiveSiblings)
{
	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	// Any live cell with more than three live neighbours dies, as if by overpopulation.
	bool resultState = false;

	// Any live cell with two or three live neighbours lives on to the next generation.
	if (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) {
		resultState = true;
	}

	return resultState;
}

int GameOfLife::checkInitialyDead(int amountOfLiveSiblings)
{
	// All other dead cells stay dead.
	bool resultState = false;

	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	if (amountOfLiveSiblings == 3) {
		resultState = true;
	}

	return resultState;
}
