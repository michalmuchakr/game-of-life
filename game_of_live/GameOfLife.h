#pragma once
class GameOfLife
{
public:
	GameOfLife(int size);

	std::unique_ptr<std::unique_ptr<std::unique_ptr<int[]>[]>[]> boardPtr;
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
