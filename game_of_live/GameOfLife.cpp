#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameOfLife.h"
#include "Board.h"
#include "Moore.h"

#define AMOUNT_OF_ITERATIONS    100
#define DELEY_BETWEEN_PROCESS   1000 //ms

template<class S, class T, class U>
GameOfLife<S, T, U>::GameOfLife()
{
}

template<class S, class T, class U>
GameOfLife<S, T, U>::GameOfLife(S* siblings, T alive, U dead, int size) : size(size), siblings(siblings)
{
    board = new Board<T, U>(alive, dead, size);
}

template<class S, class T, class U>
void GameOfLife<S, T, U>::start() const {
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

template<class S, class T, class U>
void GameOfLife<S, T, U>::processBoard() const {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            int amountOfLiveSiblings = siblings->getAmountOfLiveSiblings(i, j, board, size);

            board->boardPtr[i][j].willBeAlive = determineIfDeadOrAlive(
                amountOfLiveSiblings,
                board->boardPtr[i][j].isAlife
            );
        }
    }
}

template<class S, class T, class U>
void GameOfLife<S, T, U>::incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const {
    if (cellToCheck.isAlife) {
        amountOfLiveSiblings++;
    }
}

template<class S, class T, class U>
constexpr int GameOfLife<S, T, U>::getAmountOfLiveSiblings(int y, int x) const {
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

template<class S, class T, class U>
int GameOfLife<S, T, U>::determineIfDeadOrAlive(int amountOfLiveSiblings, bool initiallyAliveOrDead) const {
    if (initiallyAliveOrDead) {
        return checkInitiallyAlive(amountOfLiveSiblings);
    }
    else {
        return checkInitiallyDead(amountOfLiveSiblings);
    }
}

template<class S, class T, class U>
int GameOfLife<S, T, U>::checkInitiallyAlive(int amountOfLiveSiblings) const {
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    return (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) ? true : false;
}

template<class S, class T, class U>
int GameOfLife<S, T, U>::checkInitiallyDead(int amountOfLiveSiblings) const {
    // All other dead cells stay dead.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    return (amountOfLiveSiblings == 3) ? true : false;
}