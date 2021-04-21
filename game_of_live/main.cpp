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

    Game->boardPtr[1][0].isAlife = true;
    Game->boardPtr[1][2].isAlife = true;
    Game->boardPtr[2][1].isAlife = true;
    Game->boardPtr[2][2].isAlife = true;
    Game->boardPtr[3][1].isAlife = true;

    int timer = 0;

    for (int i = 0; i <= AMOUNT_OF_ITERATIONS; i++) {
        std::cout << "Iteration " << timer << std::endl;

        Game->printBoard<char, char>('#',' ');

        Game->processBoard();
        Game->syncStateOfCellBoards();

        timer++;
        Sleep(DELEY_BETWEEN_PROCESS);
        system("cls");
    }

    return 0;
}
