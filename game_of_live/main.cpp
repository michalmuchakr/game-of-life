#include <iostream>
#include <Windows.h>
#define AMOUNT_OF_ITERATIONS    100
#define DELEY_BETWEEN_PROCESS   1000 //ms
#define SIZE                    20

void printBoard(int ***);
void clearBoard(int ***);
int*** createBoard();
int getAmmountOfLiveSiblings(int ***, int, int);
int checkInitialyAlive(int);
int checkInitialyDead(int);
int determineIfDeadOrAlife(int, int);
void processBoard(int ***);
void syncStateOfCellBoards(int ***);

int main() {
    int timer = 0;
    // board[y][x][0 - current cell state, 1 - next cell state]
    int*** board = createBoard();

    clearBoard(board);

    board[1][0][0] = 1;
    board[1][2][0] = 1;
    board[2][1][0] = 1;
    board[2][2][0] = 1;
    board[3][1][0] = 1;

    while (timer < AMOUNT_OF_ITERATIONS) {
        std::cout << "Iteration " << timer << std::endl;
        processBoard(board);
        printBoard(board);
        syncStateOfCellBoards(board);
        timer++;
        Sleep(DELEY_BETWEEN_PROCESS);
        system("cls");
    }

    return 0;
}

void printBoard(int*** board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j][0] == 0) {
                std::cout << ".";
            }
            else {
                std::cout << "X";
            }
            std::cout <<  " ";
        }
        std::cout << std::endl;
    }
}

void clearBoard(int*** board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j][0] = 0;
            board[i][j][1] = 0;
        }
    }
}

int*** createBoard() {
    int*** board = new int** [SIZE];
    for (int i = 0; i < SIZE; i++) {
        board[i] = new int* [SIZE];
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = new int[2];
        }
    }

    return board;
}

// |------------- x
// | [0] [0] [0]
// | [X] [0] [X]
// | [0] [X] [X]
// y
int getAmmountOfLiveSiblings(int*** board, int y, int x) {
    int amountOfLiveSiblings = 0;

    // process vertical siblings
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {

            // out of board range - same field investigation
            if (j == x && i == y) {
                continue;
            }

            // out of board range
            if (i < 0 || i > SIZE - 1 || j < 0 || j > SIZE - 1) {
                continue;
            }

            if (board[i][j][0] == 1) {
                amountOfLiveSiblings++;
            }
        }
    }

    return amountOfLiveSiblings;
}

int checkInitialyAlive(int amountOfLiveSiblings) {
    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    int resultState = 0;

    // Any live cell with two or three live neighbours lives on to the next generation.
    if (amountOfLiveSiblings == 2 || amountOfLiveSiblings == 3) {
        resultState = 1;
    }

    return resultState;
}

int checkInitialyDead(int amountOfLiveSiblings) {
    // All other dead cells stay dead.
    int resultState = 0;

    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    if (amountOfLiveSiblings == 3) {
        resultState = 1;
    }

    return resultState;
}

int determineIfDeadOrAlife(int amountOfLiveSiblings, int initialyAliveOrDead) {
    int resultState;

    if (initialyAliveOrDead) {
        resultState = checkInitialyAlive(amountOfLiveSiblings);
    }
    else {
        resultState = checkInitialyDead(amountOfLiveSiblings);
    }

    return resultState;
}

void processBoard(int*** board) {
    // printBoard(prevBoard);
    // std::cout << std::endl << std::endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int amountOfLiveSiblings = getAmmountOfLiveSiblings(board, i, j);
            board[i][j][1] = determineIfDeadOrAlife(amountOfLiveSiblings, board[i][j][0]);
        }
    }

}

void syncStateOfCellBoards(int*** board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j][0] = board[i][j][1];
        }
    }
};