#include "Board.h"

template<class T, class U>
inline Board<T, U>::Board(T aliveCellMark, U deadCellMark, int size) {
}

template<class T, class U>
inline void Board<T, U>::printBoard() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->boardPtr[i][j].isAlife) {
                std::cout << aliveCellMark;
            } else {
                std::cout << deadCellMark;
            }
            std::cout << " ";
        }
        std::cout << std::endl;

    }
}

template<class T, class U>
inline void Board<T, U>::syncStateOfCellBoards() {
}