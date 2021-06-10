#pragma once
#include<string>

class Cell
{
public:
	short cellStatus;
	short nextStatus;

	// default constructor
	Cell();

	// copy constructor
	Cell(Cell&);

	// move constructor
	Cell(Cell&&) noexcept;

	char checkCellStatus();

	static std::string getStateNameByValue(short);

	enum CellEnum {
		BABY = 0,
		YOUNG = 1,
		ADULT = 2,
		OLD = 3,
		DEAD = 4,
	};
};
