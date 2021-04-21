#pragma once

#include <vector>
#include "Cell.h"

class GameOfLife
{
public:
	template<typename T, typename U>
	void printBoard(T alive, U dead);

	GameOfLife(int size);

	std::vector<std::vector<Cell>> boardPtr;
	int size;

	void createBoard();
	void processBoard();
	void syncStateOfCellBoards();
	int getAmmountOfLiveSiblings(int y, int x);
	int determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead);
	int checkInitialyAlive(int amountOfLiveSiblings);
	int checkInitialyDead(int amountOfLiveSiblings);
};

template<typename T, typename U>
inline void GameOfLife::printBoard(T alive, U dead)
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
