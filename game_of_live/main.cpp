#include <iostream>
#include <memory>
#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include "Moore.h"

#define SIZE 20

int main() {
    Moore * M = new Moore();

    std::unique_ptr <GameOfLife<>> Game(
        new GameOfLife<>('Q', '.', M, SIZE)
    );

    Game->start();

    return 0;
}
