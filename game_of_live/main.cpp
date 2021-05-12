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

// CELL STATE IN ENUM
// DISPLAY IS ANOTHER CASE
// NEIGHBERHOOD
// Boundary - 

// types
//main() {
//    ​​
//
//        string input = "ddd"
//
//        string output = "faasdsa"
//
//        auto board = Board<Moore, BinaryCell, SetRules1>();

//          Moore - rules for More
//          BinaryCell
//          SetRules1
//
//          board.printYourself(output);
//
//      board.executeSteps(100);

//      auto board = Board<Moore, bool, SetRules1>();
//      <typename NEIGH>
//      member -> NEIGH neigbour;
//      cell.apply(neighout, rules);

//  so we try to hide the logic of the game and 
//  in the same time create flexibility 
//  for the code where we dont createand insert 
//  object to the board, because the board create it by it self.