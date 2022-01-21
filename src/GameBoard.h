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

    std::vector<int> oneSurroundings {2, 7, 8};
    std::vector<int> twoSurroundings {1, 3, 7, 8, 9};
    std::vector<int> threeSurroundings {2, 4, 8, 9, 10};
    std::vector<int> fourSurroundings {3, 5, 9, 10, 11};
    std::vector<int> fiveSurroundings {4, 6, 10, 11, 12};
    std::vector<int> sixSurroundings {5, 11, 12};
    std::vector<int> sevenSurroundings {1, 2, 8, 13, 14};
    std::vector<int> eightSurroundings;
    std::vector<int> nineSurroundings;
    std::vector<int> tenSurroundings;
    std::vector<int> elevenSurroundings;
    std::vector<int> twelveSurroundings;
    std::vector<int> thirteenSurroundings;
    std::vector<int> fourteenSurroundings;
    std::vector<int> fifteenSurroundings;
    std::vector<int> sixteenSurroundings;
    std::vector<int> seventeenSurroundings;
    std::vector<int> eighteenSurroundings;
    std::vector<int> nineteenSurroundings;
    std::vector<int> twentySurroundings;
    std::vector<int> twentyOneSurroundings;
    std::vector<int> twentyTwoSurroundings;
    std::vector<int> twentyThreeSurroundings;
    std::vector<int> twentyFourSurroundings;
    std::vector<int> twentyFiveSurroundings;
    std::vector<int> twentySixSurroundings;
    std::vector<int> twentySevenSurroundings;
    std::vector<int> twentyEightSurroundings;
    std::vector<int> twentyNineSurroundings;
    std::vector<int> thirtySurroundings;
    std::vector<int> thirtyOneSurroundings;
    std::vector<int> thirtyTwoSurroundings;
    std::vector<int> thirtyThreeSurroundings;
    std::vector<int> thirtyFourSurroundings;
    std::vector<int> thirtyFiveSurroundings;
    std::vector<int> thirtySixSurroundings;

    std::vector<std::vector<int>> positionSurroundings {
            oneSurroundings,
            twoSurroundings,
            threeSurroundings,
            fourSurroundings,
            fiveSurroundings,
            sixSurroundings,
            sevenSurroundings,
            eightSurroundings,
            nineSurroundings,
            tenSurroundings,
            elevenSurroundings,
            twelveSurroundings,
            thirteenSurroundings,
            fourteenSurroundings,
            fifteenSurroundings,
            sixteenSurroundings,
            seventeenSurroundings,
            eighteenSurroundings,
            nineteenSurroundings,
            twentySurroundings,
            twentyOneSurroundings,
            twentyTwoSurroundings,
            twentyThreeSurroundings,
            twentyFourSurroundings,
            twentyFiveSurroundings,
            twentySixSurroundings,
            twentySevenSurroundings,
            twentyEightSurroundings,
            twentyNineSurroundings,
            thirtySurroundings,
            thirtyOneSurroundings,
            thirtyTwoSurroundings,
            thirtyThreeSurroundings,
            thirtyFourSurroundings,
            thirtyFiveSurroundings,
            thirtySixSurroundings
    };

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

    std::vector<int> getBombPositions() const;
    std::vector<std::vector<int>> getPositionSurroundings() const;
};


#endif //MINESWEEPER_GAMEBOARD_H
