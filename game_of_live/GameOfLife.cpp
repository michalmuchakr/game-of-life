#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameOfLife.h"
#include "Board.h"
#include "Moore.h"

#define AMOUNT_OF_ITERATIONS    100
#define DELEY_BETWEEN_PROCESS   1000 //ms

template<class S>
GameOfLife<S>::GameOfLife()
{
}

template<class S>
GameOfLife<S>::GameOfLife(S* siblings, int size) : size(size), siblings(siblings)
{
    board = new Board(size);
}

template<class S>
void GameOfLife<S>::start() const {
    int timer = 0;

    for (int i = 0; i <= AMOUNT_OF_ITERATIONS; i++) {
        std::cout << "Iteration " << timer << std::endl;

        board->printBoard();
        this->processBoard();
        board->syncStateOfCellBoards();

        timer++;
        Sleep(DELEY_BETWEEN_PROCESS);
        system("cls");
    }
}

template<class S>
void GameOfLife<S>::processBoard() const {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            int amountOfLiveSiblings = siblings->getAmountOfLiveSiblings(i, j, board, size);

            board->boardPtr[i][j].nextStatus = determineIfDeadOrAlive(
                amountOfLiveSiblings,
                board->boardPtr[i][j].cellStatus
            );
        }
    }
}

template<class S>
void GameOfLife<S>::incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const {
    if (cellToCheck.cellStatus) {
        amountOfLiveSiblings++;
    }
}

template<class S>
constexpr int GameOfLife<S>::getAmountOfLiveSiblings(int y, int x) const {
    int amountOfLiveSiblings = 0;

    // process vertical siblings
    for (int i = y - 1; i <= y + 1; i++) {
        // process horizontal siblings
        for (int j = x - 1; j <= x + 1; j++) {
            // same field under investigation
            if (j == x && i == y) {
                continue;
            }

            // out of boardPtr range
            if (i < 0 || i > this->size - 1 || j < 0 || j > this->size - 1) {
                continue;
            }

            // increment amount of live siblings
            incrementIfSiblingIsAlive(board->boardPtr[i][j], amountOfLiveSiblings);
        }
    }
    return amountOfLiveSiblings;
}

template<class S>
int GameOfLife<S>::determineIfDeadOrAlive(int amountOfLiveSiblings, short initiallyAliveOrDead) const {
    if (initiallyAliveOrDead == 0) {
        return checkInitiallyAlive(amountOfLiveSiblings);
    }
    else if (initiallyAliveOrDead == 4) {
        return checkInitiallyDead(amountOfLiveSiblings);
    }
}

template<class S>
short GameOfLife<S>::checkInitiallyAlive(int amountOfLiveSiblings) const {
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    return (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) ? 0 : 4;
}

template<class S>
short GameOfLife<S>::checkInitiallyDead(int amountOfLiveSiblings) const {
    // All other dead cells stay dead.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    return (amountOfLiveSiblings == 3) ? 0 : 4;
}