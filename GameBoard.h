//
// Created by Liam Ross on 20/01/2022.
//

#ifndef MINESWEEPER_GAMEBOARD_H
#define MINESWEEPER_GAMEBOARD_H

#include <string>
#include <vector>

class GameBoard {
private:
    std::string blockCharacter = "\u2588";
    std::string board[13][26];

    int numberOfBombs;
    std::vector<int> bombPositions;
    std::vector<int> playerPositions;

    int positionsRemaining;
    int positionsOpened;

public:
    GameBoard();
    void printGameBoard();
    void resetGameBoard();
    void placeBombsOnBoard();
    void addToBoard(const std::string& symbol, int position);
    void revealBoardWhenGameOver();

    bool checkPlayerPositions(int position);

    void setNumberOfBombs(int amount);
    void updatePlayerPositions(int position);

    int getPositionsRemaining() const;
    int getPositionsOpened() const;
    int getNumberOfBombs() const;

    void updatePositionsRemaining();
    void updatePositionsOpened();
};


#endif //MINESWEEPER_GAMEBOARD_H
