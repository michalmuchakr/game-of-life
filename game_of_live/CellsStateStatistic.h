#include <string>

#ifndef GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H
#define GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H

class CellsStateStatistic {
public:
    int amount;
    int cellId;
    std::string cellName;

    CellsStateStatistic();

    CellsStateStatistic(int);

    // ascending
    bool operator < (const CellsStateStatistic&) const;

    // descending
    bool operator > (const CellsStateStatistic&) const;
};

#endif //GAME_OF_LIFE_COMMANDO_BASTION_CELLSSTATESTATISTIC_H
