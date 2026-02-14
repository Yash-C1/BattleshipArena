#include "player/CPUplayer/CPUplayer.h"
#include <iostream>
#include <random>

void CPUPlayer::makeMove(Board &opponentBoard){
    static std::mt19937 rng(std::random_device{}());
    int row, col;
    do {
        row = std::uniform_int_distribution<>(0, opponentBoard.get_rows() - 1)(rng);
        col = std::uniform_int_distribution<>(0, opponentBoard.get_cols() - 1)(rng);
    } while (opponentBoard.isHit(row, col));

    std::string result = opponentBoard.recordAttack(row, col);
    std::cout << "CPU attacks (" << row << ", " << col << "): " << result << std::endl;
}

void CPUPlayer::placeShips(Board &selfBoard) {
    selfBoard.placeAllShips();
    selfBoard.display(true);
}