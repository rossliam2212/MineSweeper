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
    std::vector<int> eightSurroundings {1, 2, 3, 7, 9, 13, 14, 15};
    std::vector<int> nineSurroundings {2, 3, 4, 8, 10, 14, 15, 16};
    std::vector<int> tenSurroundings {3, 4, 5, 9, 11, 15, 16, 17};
    std::vector<int> elevenSurroundings {4, 5, 6, 10, 12, 16, 17, 18};
    std::vector<int> twelveSurroundings {5, 6, 11, 17, 18};
    std::vector<int> thirteenSurroundings {7, 8, 14, 19, 20};
    std::vector<int> fourteenSurroundings {7, 8, 9, 13, 15, 19, 20, 21};
    std::vector<int> fifteenSurroundings {8, 9, 10, 14, 16, 20, 21, 22};
    std::vector<int> sixteenSurroundings {9, 10, 11, 15, 17, 21, 22, 23};
    std::vector<int> seventeenSurroundings {10, 11, 12, 16, 18, 22, 23, 24};
    std::vector<int> eighteenSurroundings {11, 12, 17, 23, 24};
    std::vector<int> nineteenSurroundings {13, 14, 20, 25, 26};
    std::vector<int> twentySurroundings {13, 14, 15, 19, 21, 25, 26, 27};
    std::vector<int> twentyOneSurroundings {14, 15, 16, 20, 22, 26, 27, 28};
    std::vector<int> twentyTwoSurroundings {15, 16, 17, 21, 23, 27, 28, 29};
    std::vector<int> twentyThreeSurroundings {16, 17, 18, 22, 24, 28, 29, 30};
    std::vector<int> twentyFourSurroundings {17, 18, 23, 29, 30};
    std::vector<int> twentyFiveSurroundings {19, 20, 26, 31, 32};
    std::vector<int> twentySixSurroundings {19, 20, 21, 25, 27, 31, 32, 33};
    std::vector<int> twentySevenSurroundings {20, 21, 22, 26, 28, 32, 33, 34};
    std::vector<int> twentyEightSurroundings {21, 22, 23, 27, 29, 33, 34, 35};
    std::vector<int> twentyNineSurroundings {22, 23, 24, 28, 30, 34, 35, 36};
    std::vector<int> thirtySurroundings {23, 24, 29, 35, 36};
    std::vector<int> thirtyOneSurroundings {25, 26, 32};
    std::vector<int> thirtyTwoSurroundings {25, 26, 27, 31, 33};
    std::vector<int> thirtyThreeSurroundings {26, 27, 28, 32, 34};
    std::vector<int> thirtyFourSurroundings {27, 28, 29, 33, 35};
    std::vector<int> thirtyFiveSurroundings {28, 29, 30, 34, 36};
    std::vector<int> thirtySixSurroundings {29, 30, 35};

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
