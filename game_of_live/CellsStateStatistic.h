//
// Created by michal on 04.06.2021.
//

#include <string>

#ifndef GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H
#define GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H

class CellsStateStatistic {
public:
    int amount;
    int cellId;
    std::string cellName;

    CellsStateStatistic();

    CellsStateStatistic(int cellId);

    // ascending
    bool operator < (const CellsStateStatistic& str) const;
    
    // descending
    bool operator > (const CellsStateStatistic& str) const;
};

#endif //GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H
