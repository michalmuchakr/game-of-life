#include "Moore.h"
#include "Neumann.h"

Neumann::Neumann()
{
}

void Neumann::incrementIfSiblingIsAlive(const Cell& cellToCheck, int& amountOfLiveSiblings) const
{
    if (cellToCheck.cellStatus != 4)
    {
        amountOfLiveSiblings++;
    }
}

int Neumann::getAmountOfLiveSiblings(int y, int x, const Board* board, int size)
{
    int amountOfLiveSiblings = 0;

    // process vertical siblings
    for (int i = y - 1; i <= y + 1; i++)
    {
        // process horizontal siblings
        for (int j = x - 1; j <= x + 1; j++)
        {
            // same field under investigation
            if (checkNeighborhoodForNeumann(x, y))
            {
                if (j == x && i == y) {
                    continue;
                }
            }

            // out of boardPtr range
            if (i < 0 || i > size - 1 || j < 0 || j > size - 1)
            {
                continue;
            }

            // increment amount of live siblings
            incrementIfSiblingIsAlive(board->boardPtr[i][j], amountOfLiveSiblings);
        }
    }

    return amountOfLiveSiblings;
}

bool Neumann::checkNeighborhoodForNeumann(int x, int y)
{
    // exclude the cells in the corners
    return !(x - 1 && y - 1 || x + 1 && y - 1 || x - 1 && y + 1 || x + 1 && y + 1) ? true : false;
}
