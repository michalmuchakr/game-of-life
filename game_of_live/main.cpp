#include <iostream>
#include <memory>
#include "GameOfLife.h"
#include "GameOfLife.cpp"

#define SIZE 20

int main() {
    std::unique_ptr <GameOfLife<>> Game(new GameOfLife<>('Q', '.', SIZE));

    Game->start();

    return 0;
}
