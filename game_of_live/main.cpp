#include <iostream>
#include <memory>
#include "GameOfLife.h"
#include "GameOfLife.cpp"
#include "Moore.h"

#define SIZE 20

int main() {
    Moore * M = new Moore();
    M->getAmmountOfLiveSiblings();
    std::unique_ptr <GameOfLife<char, char, Moore>> Game(
        new GameOfLife<char, char, Moore>('Q', '.', SIZE)
    );

    Game->start();

    return 0;
}