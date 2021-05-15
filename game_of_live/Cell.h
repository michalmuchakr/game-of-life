#pragma once
class Cell
{
public:
	short cellStatus;
	short nextStatus;

	// default constructor
	Cell();

	// copy constructor
	Cell(Cell& C1);

	// move constructor
	Cell(Cell&& C1) noexcept;

	char checkCellStatus();
};