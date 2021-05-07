#include <iostream>
#include <vector>
#include "GameOfLife.h"
//
//template<class T, class U>
//GameOfLife<T, U>::GameOfLife(T alive, U dead, const int size) : dead(dead), alive(alive), size(size) {}

template<class T, class U>
GameOfLife<T, U>::GameOfLife(T alive, U dead, const int size) : dead(dead), alive(alive), size(size) {
    
}

template<class T, class U>
void GameOfLife<T, U>::printBoard() const {
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

template<class T, class U>
void GameOfLife<T, U>::createBoard() {
    // Cell board
    boardPtr.resize(this->size);
    for (int i = 0; i < this->size; i++) {
        boardPtr[i].resize(this->size);
        for (int j = 0; j < this->size; j++) {
            // cells' prev and next state
            boardPtr[i].push_back(Cell());
        }
    }
}

template<class T, class U>
void GameOfLife<T, U>::processBoard() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            int amountOfLiveSiblings = getAmmountOfLiveSiblings(i, j);
            this->boardPtr[i][j].willBeAlive = determineIfDeadOrAlife(
                                                    amountOfLiveSiblings,
                                                    this->boardPtr[i][j].isAlife
                                                );
        }
    }
}

template<class T, class U>
void GameOfLife<T, U>::syncStateOfCellBoards() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->boardPtr[i][j].isAlife = this->boardPtr[i][j].willBeAlive;
        }
    }
}

template<class T, class U>
void GameOfLife<T, U>::incrementIfSiblingIsAlife(const Cell & cellToCheck, int& amountOfLiveSiblings) {
    if (cellToCheck.isAlife) {
        amountOfLiveSiblings++;
    }
}

template<class T, class U>
constexpr int GameOfLife<T, U>::getAmmountOfLiveSiblings(int y, int x) {
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
            incrementIfSiblingIsAlife(this->boardPtr[i][j], amountOfLiveSiblings);
        }
    }
    return amountOfLiveSiblings;
}

template<class T, class U>
int GameOfLife<T, U>::determineIfDeadOrAlife(int amountOfLiveSiblings, bool initialyAliveOrDead) {
    if (initialyAliveOrDead) {
        return checkInitialyAlive(amountOfLiveSiblings);
    }
    else {
        return checkInitialyDead(amountOfLiveSiblings);
    }
}

template<class T, class U>
int GameOfLife<T, U>::checkInitialyAlive(int amountOfLiveSiblings)  {
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    return (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) ? true : false;
}

template<class T, class U>
int GameOfLife<T, U>::checkInitialyDead(int amountOfLiveSiblings) {
    // All other dead cells stay dead.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    return (amountOfLiveSiblings == 3) ? true : false;
}