#pragma once

#include <vector>

class GameOfLife
{
public:
	GameOfLife(int size);

	std::vector<std::vector<std::vector<int>>> boardPtr;
	int size;

	void createBoard();
	void printBoard();
	void processBoard();
	void syncStateOfCellBoards();
	int getAmmountOfLiveSiblings(int y, int x);
	int determineIfDeadOrAlife(int amountOfLiveSiblings, int initialyAliveOrDead);
	int checkInitialyAlive(int amountOfLiveSiblings);
	int checkInitialyDead(int amountOfLiveSiblings);
};
