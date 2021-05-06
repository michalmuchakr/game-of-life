#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell():
	isAlife(false),
	willBeAlive(false)
{
}

Cell::Cell(Cell& C1)
{
	this->isAlife = C1.isAlife;
	this->willBeAlive = C1.willBeAlive;
}

Cell::Cell(Cell&& C1) noexcept
{
	this->isAlife = std::move(C1.isAlife);
	this->willBeAlive = std::move(C1.willBeAlive);
}
