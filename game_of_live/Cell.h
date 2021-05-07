#pragma once
class Cell
{
public:
	bool isAlife;
	bool willBeAlive;

	// default constructor
	Cell();

	// copy constructor
	Cell(Cell& C1);

	// move constructor
	Cell(Cell&& C1) noexcept;
};