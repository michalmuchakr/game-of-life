#include <iostream>
#include <windows.h>
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        return 'N';
        break;
    case YOUNG:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        return 'Y';
        break;
    case ADULT:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        return 'A';
        break;
    case OLD:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        return 'O';
        break;
    case DEAD:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return '.';
        break;
    default:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return '.';
        break;
    }
}

class CellTest {
protected:
	CellEnum state;
};