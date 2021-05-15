#include <iostream>
#include <memory>
#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include "Moore.h"
#include "Neumann.h"

#define SIZE 20

int main() {

    Moore* M = new Moore();
    Neumann* N = new Neumann();

    std::unique_ptr <GameOfLife<Moore>> Game(
        new GameOfLife<Moore>(M, SIZE)
    );

    Game->start();

    return 0;
}
