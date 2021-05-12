#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameOfLife.h"
#include "Board.h"
#include "Moore.h"

#define AMOUNT_OF_ITERATIONS    100
#define DELEY_BETWEEN_PROCESS   1000 //ms

template<class T, class U, class S>
GameOfLife<T, U, S>::GameOfLife()
{
}

template<class T, class U, class S>
GameOfLife<T, U, S>::GameOfLife(T alive, U dead, S* sibl, int size) : size(size)
{
    board = new Board<T, U>(alive, dead, size);
    siblings = sibl;
}

template<class T, class U, class S>
void GameOfLife<T, U, S>::start() const {
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

template<class T, class U, class S>
void GameOfLife<T, U, S>::processBoard() const {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
             int amountOfLiveSiblings = siblings->getAmmountOfLiveSiblings(i, j, board, size);

             board->boardPtr[i][j].willBeAlive = determineIfDeadOrAlife(
                                                    amountOfLiveSiblings,
                                                    board->boardPtr[i][j].isAlife
                                                );
        }
    }
}

template<class T, class U, class S>
void GameOfLife<T, U, S>::incrementIfSiblingIsAlife(const Cell & cellToCheck, int& amountOfLiveSiblings) const {
    if (cellToCheck.isAlife) {
        amountOfLiveSiblings++;
    }
}

template<class T, class U, class S>
constexpr int GameOfLife<T, U, S>::getAmmountOfLiveSiblings(int y, int x) const {
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
            incrementIfSiblingIsAlife(board->boardPtr[i][j], amountOfLiveSiblings);
        }
    }

    return amountOfLiveSiblings;
}

template<class T, class U, class S>
int GameOfLife<T, U, S>::determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead) const {
    if (initialyAliveOrDead) {
        return checkInitialyAlive(amountOfLiveSiblings);
    }
    else {
        return checkInitialyDead(amountOfLiveSiblings);
    }
}

template<class T, class U, class S>
int GameOfLife<T, U, S>::checkInitialyAlive(int amountOfLiveSiblings) const {
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    return (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) ? true : false;
}

template<class T, class U, class S>
int GameOfLife<T, U, S>::checkInitialyDead(int amountOfLiveSiblings) const {
    // All other dead cells stay dead.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    return (amountOfLiveSiblings == 3) ? true : false;
}