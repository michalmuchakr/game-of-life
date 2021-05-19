#include <iostream>
#include "Cell.h"

using namespace std;

enum CellEnum {
    NEWBORN = 0,
    YOUNG = 1,
    ADULT = 2,
    OLD = 3,
    DEAD = 4,
};

Cell::Cell() : cellStatus(4), nextStatus(4) {}

Cell::Cell(Cell& C1)
{
	this->cellStatus = C1.cellStatus;
	this->nextStatus = C1.nextStatus;
}

Cell::Cell(Cell&& C1) noexcept
{
	this->cellStatus = std::move(C1.cellStatus);
	this->nextStatus = std::move(C1.nextStatus);
}

char Cell::checkCellStatus() {
    switch (cellStatus) {
    case NEWBORN:
        return 'N';
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