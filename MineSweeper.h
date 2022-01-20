//
// Created by Liam Ross on 18/01/2022.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include <string>
#include <vector>

class MineSweeper {
private:
    bool gameRunning;

    std::string playerName;

    std::string blockCharacter = "\u2588";
    std::string gameBoard[13][26];

    int numberOfBombs;
    std::vector<int> bombPositions;

    int score;
    int positionsOpened;
    int positionsRemaining;

public:
    explicit MineSweeper(std::string name);
    void startGame();

    enum GameMode {
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
    bool setGameMode(int input);
    void placeBombs();
    bool checkPlayerPosition(int position);
    void handlePlayerMove(int row, int col);
//    void checkWin();
    void handleWin();
    bool checkPositionInput(int row, int col);
    void printGameBoard(std::string board[13][26]);
    void updateGameBoard(bool bomb, int position);
    void revealGameBoardWhenGameOver();
    void printBoardPositions();
};


#endif //MINESWEEPER_MINESWEEPER_H
