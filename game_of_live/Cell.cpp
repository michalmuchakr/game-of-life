#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell(): isAlive(false), willBeAlive(false)
{
}

Cell::Cell(Cell& C1)
{
	this->isAlive = C1.isAlive;
	this->willBeAlive = C1.willBeAlive;
}

Cell::Cell(Cell&& C1) noexcept
{
	this->isAlive = std::move(C1.isAlive);
	this->willBeAlive = std::move(C1.willBeAlive);
}
