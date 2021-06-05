#include <iostream>
#include <windows.h>
#include "Cell.h"

using namespace std;

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
    case BABY:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        return 'B';
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

std::string Cell::getStateNameByValue(short cellStatus)
{
    switch (cellStatus) {
    case BABY:
        return "BABY";
        break;
    case YOUNG:
        return "YOUNG";
        break;
    case ADULT:
        return "ADULT";
        break;
    case OLD:
        return "OLD";
        break;
    case DEAD:
        return "DEAD";
        break;
    default:
        return "DEAD";
        break;
    }
}
