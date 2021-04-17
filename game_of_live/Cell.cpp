#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell(): isAlife(false), willBeAlive(false)
{
	std::cout << "Default constructor." << std::endl;
}

Cell::Cell(Cell& C1)
{
	std::cout << "Copy constructor." << std::endl;
	this->isAlife = C1.isAlife;
	this->willBeAlive = C1.willBeAlive;
}

Cell::Cell(Cell&& C1) noexcept
{
	std::cout << std::endl << "Move semantics constructor." << std::endl << std::endl;
	this->isAlife = std::move(C1.isAlife);
	this->willBeAlive = std::move(C1.willBeAlive);
}
