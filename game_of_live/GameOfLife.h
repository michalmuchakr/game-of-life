#pragma once
class GameOfLife
{
public:
	GameOfLife(int size);

	int size;
	int*** board;

	void start();
	void createBoard();
	void nullBoard();
	void printBoard();
	void processBoard();
	void syncStateOfCellBoards();
	int getAmmountOfLiveSiblings(int y, int x);
	int determineIfDeadOrAlife(int amountOfLiveSiblings, int initialyAliveOrDead);
	int checkInitialyAlive(int amountOfLiveSiblings);
	int checkInitialyDead(int amountOfLiveSiblings);
};
