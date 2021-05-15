#include "Moore.h"
#include "Board.h"

Moore::Moore()
{
}

void Moore::incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const
{
    if (cellToCheck.cellStatus == 0) {
        amountOfLiveSiblings++;
    }
}

int Moore::getAmountOfLiveSiblings(int y, int x, const Board* board, int size)
{
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
            if (i < 0 || i > size - 1 || j < 0 || j > size - 1) {
                continue;
            }

            // increment amount of live siblings
            incrementIfSiblingIsAlive(board->boardPtr[i][j], amountOfLiveSiblings);
        }
    }

    return amountOfLiveSiblings;
}