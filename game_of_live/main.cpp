#include <iostream>
#include <memory>
#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include "Moore.h"
#include "Neumann.h"
#include <map>

int main() {
    Moore* M = new Moore();
    Neumann* N = new Neumann();

    std::unique_ptr <GameOfLife<Moore>> Game(
        new GameOfLife<Moore>(M)
    );

    Game->start();

    return 0;
}
