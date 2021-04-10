#include <iostream>
#include <Windows.h>
#include <memory>
#include "GameOfLife.h"

#define AMOUNT_OF_ITERATIONS    100
#define DELEY_BETWEEN_PROCESS   1000 //ms
#define SIZE                    20

int main() {
    std::unique_ptr<GameOfLife> Game(new GameOfLife(SIZE));
    Game->createBoard();
    Game->nullBoard();

    Game->board[1][0][0] = 1;
    Game->board[1][2][0] = 1;
    Game->board[2][1][0] = 1;
    Game->board[2][2][0] = 1;
    Game->board[3][1][0] = 1;

    int timer = 0;

    while (timer < AMOUNT_OF_ITERATIONS) {
        std::cout << "Iteration " << timer << std::endl;

        Game->processBoard();
        Game->printBoard();
        Game->syncStateOfCellBoards();

        timer++;
        Sleep(DELEY_BETWEEN_PROCESS);
        system("cls");
    }

    return 0;
}
