#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include "GameOfLife.h"
#include "Board.h"
#include "Moore.h"
#include "AmountOfTryExceptions.h"

#define DELEY_BETWEEN_PROCESS   1000 //ms
#define AMOUNT_OF_ITERATIONS    100 


template<class S>
GameOfLife<S>::GameOfLife()
{
}

template<class S>
GameOfLife<S>::GameOfLife(S* siblings) : siblings(siblings), anountOfUserProvideBoardSize(0), anountOfUserProvideBoardSizeLimit(2)
{
}

template<class S>
void GameOfLife<S>::start() const
{
    initUserBoardSize();
    initBoard();
    initThreadVector();

    int timer = 0;

    for (int i = 0; i <= AMOUNT_OF_ITERATIONS; i++)
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Iteration " << timer << std::endl;

        board->calcAndPrintBoardCellStatists();

        board->printBoard();

        this->processBoard();

        this->ageUpAliveCell();

        board->syncStateOfCellBoards();

        timer++;

        Sleep(DELEY_BETWEEN_PROCESS);
        system("cls");
    }
}

template<class S>
void GameOfLife<S>::initUserBoardSize() const
{
    try
    {
        getUserSizeOfBoard();
    }
    catch (const std::out_of_range& oorError)
    {
        handleBoardError(oorError.what());
    }
    catch (AmountOfTryExceptions& aotError)
    {
        handleAmountOfTryError(aotError.what());
    }
}

template<class S>
void GameOfLife<S>::initBoard() const
{
    board = new Board(size);
}

template<class S>
void GameOfLife<S>::initThreadVector() const
{
    this->board->threadVector.resize(this->size);
}

template<class S>
void GameOfLife<S>::getUserSizeOfBoard() const
{
    if (this->anountOfUserProvideBoardSize > this->anountOfUserProvideBoardSizeLimit)
    {
        throw AmountOfTryExceptions();
    }

    std::cout << "Please provide size of board, is going to be a square" << std::endl;
    std::cout << "Please provide number from range <1, 500>" << std::endl;

    std::cin >> this->size;

    this->anountOfUserProvideBoardSize += 1;

    if (this->size < 1)
    {
        throw std::out_of_range("Size provided is to small!");
    }
    else if (this->size > 500)
    {
        throw std::out_of_range("Size provided is to big!");
    }
}

template<class S>
void GameOfLife<S>::handleBoardError(std::string errorMsg) const
{
    std::string userDecision;

    std::cerr << "Out of Range error: " << errorMsg << '\n';
    std::cout << "Would you like to try again, [Y] = yes, [other] = no" << std::endl;

    std::cin >> userDecision;

    if (userDecision == "Y")
    {
        system("cls");
        initUserBoardSize();
    }
    else
    {
        std::cout << "Program going to be closed." << std::endl;
        std::exit(1);
    }
}

template<class S>
void GameOfLife<S>::handleAmountOfTryError(std::string errorMsg) const
{
    std::cout << errorMsg << std::endl << "Program going to be closed, press any to continue." << std::endl;
    std::exit(1);
}

template<class S>
void GameOfLife<S>::processBoard() const
{
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            int amountOfLiveSiblings = siblings->getAmountOfLiveSiblings(i, j, board, size);

            board->boardPtr[i][j].nextStatus = determineIfDeadOrAlive(
                amountOfLiveSiblings,
                board->boardPtr[i][j].cellStatus
            );
        }
    }
}

template<class S>
void GameOfLife<S>::incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const
{
    if (cellToCheck.cellStatus != Cell::DEAD)
    {
        amountOfLiveSiblings++;
    }
}

template<class S>
void GameOfLife<S>::ageUpAliveCell() const
{
    auto ageUpParticularCell = [=](int i, int j)
    {
        Cell temC = this->board->boardPtr[i][j];

        // NEWBORN state cell at cellStatus assumes that it remain alive at NEWBORN state
        // and it's not turned from dead to alive
        // --> (temC.cellStatus == 0 && temC.nextStatus == 0)

        // rest of not dead cell needs to get older
        // dead cells do not get older

        if ((temC.cellStatus == 0 && temC.nextStatus == 0) || (temC.nextStatus > 0 && temC.nextStatus < 4))
        {
            return this->board->boardPtr[i][j].nextStatus + 1;
        }
    };

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            this->board->boardPtr[i][j].nextStatus = ageUpParticularCell(i, j);
        }
    }
}

template<class S>
constexpr int GameOfLife<S>::getAmountOfLiveSiblings(int y, int x) const
{
    int amountOfLiveSiblings = 0;

    // process vertical siblings
    for (int i = y - 1; i <= y + 1; i++)
    {
        // process horizontal siblings
        for (int j = x - 1; j <= x + 1; j++)
        {
            // same field under investigation
            if (j == x && i == y)
            {
                continue;
            }

            // out of boardPtr range
            if (i < 0 || i > this->size - 1 || j < 0 || j > this->size - 1)
            {
                continue;
            }

            // increment amount of live siblings
            incrementIfSiblingIsAlive(board->boardPtr[i][j], amountOfLiveSiblings);
        }
    }
    return amountOfLiveSiblings;
}

template<class S>
int GameOfLife<S>::determineIfDeadOrAlive(int amountOfLiveSiblings, short initiallyCellState) const
{
    if (initiallyCellState != 4)
    {
        return checkInitiallyAlive(amountOfLiveSiblings, initiallyCellState);
    }
    else if (initiallyCellState == 4)
    {
        return checkInitiallyDead(amountOfLiveSiblings);
    }
}

template<class S>
short GameOfLife<S>::checkInitiallyAlive(int amountOfLiveSiblings, short initiallyCellState) const
{
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    return (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) ? initiallyCellState : 4;
}

template<class S>
short GameOfLife<S>::checkInitiallyDead(int amountOfLiveSiblings) const
{
    // All other dead cells stay dead.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    return (amountOfLiveSiblings == 3) ? 0 : 4;
}

template<class S>
void GameOfLife<S>::calcAndPrintBoardStatistic() const
{
}
