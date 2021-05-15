#include <iostream>
#include "Cell.h"

using namespace std;

enum CellEnum {
    ALIVE = 0,
    YOUNG = 1,
    ADULT = 2,
    OLD = 3,
    DEAD = 4,
};

//Cell::Cell() : isAlife(false), willBeAlive(false)
//{
//}

Cell::Cell() : cellStatus(4) {}

Cell::Cell(Cell& C1)
{
	this->cellStatus = C1.cellStatus;
}

Cell::Cell(Cell&& C1) noexcept
{
	this->cellStatus = std::move(C1.cellStatus);
}

char Cell::checkCellStatus() {
    switch (cellStatus) {
    case ALIVE:
        return '#';
        break;
    case YOUNG:
        return 'Y';
        break;
    case ADULT:
        return 'A';
        break;
    case OLD:
        return 'O';
        break;
    case DEAD:
        return '.';
        break;
    default:
        return '.';
        break;
    }
}

class CellTest {
protected:
	CellEnum state;
};