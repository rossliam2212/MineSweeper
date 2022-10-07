//
// Created by Liam Ross on 18/01/2022.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include <string>
#include <vector>
#include "GameBoard.h"
#include "WinTracker.h"

class MineSweeper {
private:
    bool gameRunning;
    std::string playerName;
    std::string blockCharacter = "\u2588";
    GameBoard board;
    int score;

    WinTracker winTracker;

public:
    explicit MineSweeper(const std::string& name);
    void startGame();
    void resetGame();

    enum GameMode {
        idle,
        oneBomb,
        threeBomb,
        fiveBomb,
        tenBomb,
        twentyBomb,
        thirtyFiveBomb
    };

private:
    GameMode gameMode;
    void printWelcome();
    void printInstructions();
    void printGameDetails() const;

    void handleGameMode();
    bool setGameMode(int input);

    void handlePlayerMove(int row, int col);
    void handleWin();
    static bool checkPositionInput(int row, int col);
    int calculateNumberForBoard(int position);
    void setPlayerPosition(int position);

    void updatePlayerWins();

};


#endif //MINESWEEPER_MINESWEEPER_H
