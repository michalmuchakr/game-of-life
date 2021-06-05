//
// Created by micha on 04.06.2021.
//

#include "CellsStateStatistic.h"
#include "Cell.h"

CellsStateStatistic::CellsStateStatistic() : amount(0), cellId(0), cellName("")
{
}

CellsStateStatistic::CellsStateStatistic(int cellId): amount(cellId), cellId(cellId)
{
	this->cellName = Cell::getStateNameByValue(cellId);
}

bool CellsStateStatistic::operator < (const CellsStateStatistic& CellsStat) const
{
	return (amount < CellsStat.amount);
}

bool CellsStateStatistic::operator > (const CellsStateStatistic& CellsStat) const
{
	return (amount > CellsStat.amount);
}