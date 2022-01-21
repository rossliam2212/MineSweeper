//
// Created by Liam Ross on 20/01/2022.
//

#include <iostream>
#include "GameBoard.h"

GameBoard::GameBoard() :
    board{{" "," ", " ", " ", "1", " ",  "|", " ", "2", " ", "|", " ", "3", " ", "|", " ", "4", " ", "|", " ", "5", " ", "|", " ", "6", " "},
             {" "," ", " ", " ", " ", " ",  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
             {"1","|", " ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "},
             {" "," ", " ", "-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
             {"2","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "},
             {" "," ", " ","-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
             {"3","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "},
             {" "," ", " ","-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
             {"4","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "},
             {" "," ", " ","-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
             {"5","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "},
             {" "," ",    " ","-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
             {"6","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "}},
     numberOfBombs{},
     bombPositions{},
     playerPositions{},
     positionsRemaining{36},
     positionsOpened{} {
    srand((unsigned) time(nullptr));
}

void GameBoard::printGameBoard() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 26; j++) {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
}

void GameBoard::resetGameBoard() {
    for (int i = 1; i <= 36; i++)
        addToBoard(blockCharacter, i);

    playerPositions.clear();
    bombPositions.clear();

}

void GameBoard::placeBombsOnBoard() {
    for (int i = 0; i < numberOfBombs; i++) {
        int randomPosition = (rand() % 36) + 1;

        while (std::find(bombPositions.begin(), bombPositions.end(), randomPosition) != bombPositions.end())
            randomPosition = (rand() % 36) + 1;

        bombPositions.push_back(randomPosition);
    }

    // ---- For testing
    for(int i = 1; i <= 36; i++) {
        if (std::find(bombPositions.begin(), bombPositions.end(), i) != bombPositions.end()) {
            continue;
        }
        std::cout << "======= " << i << std::endl;
    }
 }

void GameBoard::revealBoardWhenGameOver() {
    std::string bomb{"\x1B[91mX\x1B[97m"};

    for (int position : bombPositions)
        addToBoard(bomb, position);

    printGameBoard();
}

void GameBoard::addToBoard(const std::string& symbol, int position) {
    switch (position) {
        case 1:
            board[2][4] = symbol;
            break;
        case 2:
            board[2][8] = symbol;
            break;
        case 3:
            board[2][12] = symbol;
            break;
        case 4:
            board[2][16] = symbol;
            break;
        case 5:
            board[2][20] = symbol;
            break;
        case 6:
            board[2][24] = symbol;
            break;
        case 7:
            board[4][4] = symbol;
            break;
        case 8:
            board[4][8] = symbol;
            break;
        case 9:
            board[4][12] = symbol;
            break;
        case 10:
            board[4][16] = symbol;
            break;
        case 11:
            board[4][20] = symbol;
            break;
        case 12:
            board[4][24] = symbol;
            break;
        case 13:
            board[6][4] = symbol;
            break;
        case 14:
            board[6][8] = symbol;
            break;
        case 15:
            board[6][12] = symbol;
            break;
        case 16:
            board[6][16] = symbol;
            break;
        case 17:
            board[6][20] = symbol;
            break;
        case 18:
            board[6][24] = symbol;
            break;
        case 19:
            board[8][4] = symbol;
            break;
        case 20:
            board[8][8] = symbol;
            break;
        case 21:
            board[8][12] = symbol;
            break;
        case 22:
            board[8][16] = symbol;
            break;
        case 23:
            board[8][20] = symbol;
            break;
        case 24:
            board[8][24] = symbol;
            break;
        case 25:
            board[10][4] = symbol;
            break;
        case 26:
            board[10][8] = symbol;
            break;
        case 27:
            board[10][12] = symbol;
            break;
        case 28:
            board[10][16] = symbol;
            break;
        case 29:
            board[10][20] = symbol;
            break;
        case 30:
            board[10][24] = symbol;
            break;
        case 31:
            board[12][4] = symbol;
            break;
        case 32:
            board[12][8] = symbol;
            break;
        case 33:
            board[12][12] = symbol;
            break;
        case 34:
            board[12][16] = symbol;
            break;
        case 35:
            board[12][20] = symbol;
            break;
        case 36:
            board[12][24] = symbol;
            break;
        default:
            break;
    }
}

bool GameBoard::checkPlayerPositions(int position) {
    if (std::find(bombPositions.begin(), bombPositions.end(), position) != bombPositions.end())
        return true;
    return false;
}

void GameBoard::setNumberOfBombs(int amount) {
    numberOfBombs = amount;
}

void GameBoard::updatePlayerPositions(int position) {
    playerPositions.push_back(position);
}

std::vector<int> GameBoard::getBombPositions() const {
    return bombPositions;
}

std::vector<std::vector<int>> GameBoard::getPositionSurroundings() const {
    return positionSurroundings;
}

/**
 * @return The number of bombs.
 */
int GameBoard::getNumberOfBombs() const {
    return numberOfBombs;
}

/**
 * @return The number of positions remaining on the board.
 */
int GameBoard::getPositionsRemaining() const {
    return positionsRemaining;
}

/**
 * @return The number of positions opened by the player.
 */
int GameBoard::getPositionsOpened() const {
    return positionsOpened;
}

/**
 * Decrements the positions remaining after each move by the player.
 */
void GameBoard::updatePositionsRemaining() {
    positionsRemaining--;
}

/**
 * Increments the positions after each move by the player.
 */
void GameBoard::updatePositionsOpened() {
    positionsOpened++;
}


