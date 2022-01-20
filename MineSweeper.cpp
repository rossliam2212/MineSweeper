//
// Created by Liam Ross on 18/01/2022.
//

#include <iostream>
#include <ctime>
#include <utility>
#include "MineSweeper.h"

#define underline "\033[4m" // Add underline to text
#define removeUnderline "\033[0m" // Remove underline from text
#define green "\x1B[32m" // Make text green
#define red "\x1B[31m" // Make text red
#define white "\x1B[97m" // Make text white

MineSweeper::MineSweeper(std::string name) :
      gameBoard{{" "," ", " ", " ", "1", " ",  "|", " ", "2", " ", "|", " ", "3", " ", "|", " ", "4", " ", "|", " ", "5", " ", "|", " ", "6", " "},
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
                {" "," ", " ","-", "-", "-", "+", "-", "-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-", "+", "-","-", "-"},
                {"6","|"," ", " ", blockCharacter, " ",  "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " ", "|", " ", blockCharacter, " "}},
      playerName{std::move(name)},
      gameRunning{false},
      bombPositions{},
      numberOfBombs{0},
      gameMode{idle},
      score{0},
      playerPositions{},
      positionsOpened{0},
      positionsRemaining{36} {
    srand((unsigned) time(nullptr));
}

void MineSweeper::startGame() {
    printWelcome();
    printInstructions();

    char choice;
    std::cout << "\nReady to play? (y/n)\n>";
    std::cin >> choice;
    while(choice != 'y' && choice != 'n') {
        std::cout << "\nInvalid option. Try again. (y/n)\n>";
        std::cin >> choice;
    }

    if (choice == 'y') {
        gameRunning = true;
        std::cout << underline << green << "=== Game Started ===\n" << white << removeUnderline <<  std::endl;
        printGameBoard(gameBoard);

        while (gameRunning) {
            int row;
            int col;
            printGameDetails();
            std::cout <<"\n\nEnter the position you want to reveal.\n"
                            "Make sure to enter in the format - [Row] [Space] [Column]\n>";
            std::cin >> row >> col;

            while (!std::cin || !checkPositionInput(row, col)) {
                std::cout << "Invalid position! Try again - [Row] [Space] [Column] \n>";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> row >> col;
            }
            handlePlayerMove(row, col);
        }
    } else {
        std::cout << "\nThat's okay! Come back soon." << std::endl;
    }
}

/**
 * This function makes sure that the position the player chooses to reveal is valid.
 * @param row The row.
 * @param col The column.
 * @return True if the position is valid, False otherwise.
 */
bool MineSweeper::checkPositionInput(int row, int col) {
    if (row <= 6 && row >= 1 && col <= 6 && col >= 1)
        return true;
    return false;
}

/**
 * This function prints the welcome message before the game starts.
 * This is also where the players chooses which game mode they want to play.
 */
void MineSweeper::printWelcome() {
    std::cout << green << "\n===== Welcome to Mine Sweeper " << playerName << " =====" << white << std::endl;
    std::cout << "\nHere are the game modes:\n" <<
                 "\t- One Bomb\n" <<
                 "\t- Three Bombs\n" <<
                 "\t- Five Bombs\n" <<
                 "\t- Ten Bombs\n" <<
                 "\t- Twenty Bombs\n" <<
                 "\t- Thirty Five Bombs\n";

    std::cout << "\nWhich would you like to play? (1/3/5/10/20/35)\n>";
    int decision;
    std::cin >> decision;

    while (!std::cin || !setGameMode(decision)) {
        std::cout << "Sorry that's not a game mode! Try again! (1/3/5/10/20/35) \n>";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> decision;
    }
}

/*
 * This function sets the game mode based on the players input.
 */
bool MineSweeper::setGameMode(int input) {
    switch (input) {
        case 1:
            gameMode = oneBomb;
            numberOfBombs = 1;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " One Bomb" << std::endl;
            break;
        case 3:
            gameMode = threeBomb;
            numberOfBombs = 3;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Three Bombs" << std::endl;
            break;
        case 5:
            gameMode = fiveBomb;
            numberOfBombs = 5;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Five Bombs" << std::endl;
            break;
        case 10:
            gameMode = tenBomb;
            numberOfBombs = 10;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Ten Bombs" << std::endl;
            break;
        case 20:
            gameMode = twentyBomb;
            numberOfBombs = 20;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Twenty Bombs" << std::endl;
            break;
        case 35:
            gameMode = thirtyFiveBomb;
            numberOfBombs = 35;
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Thirty Five Bombs" << std::endl;
            break;
        default:
            return false;
    }
    placeBombs();
    return true;
}

/**
 * This function randomly chooses the positions for the bombs based on the game mode chosen by the player.
 * The bombs positions range from 1 to 36, as there are 36 positions on the board.
 */
void MineSweeper::placeBombs() {
    for (int i = 0; i < numberOfBombs; i++) {
        int random = (rand() % 36) + 1;

        while (std::find(bombPositions.begin(), bombPositions.end(), random) != bombPositions.end()) {
            random = (rand() % 36) + 1;
        }
        bombPositions.push_back(random);
    }

    // --- For Testing ---
    for (int& i : bombPositions) {
        std::cout << i << " ";
    }

    for (int i = 0; i < 36; i++) {
        if (std::find(bombPositions.begin(), bombPositions.end(), i) != bombPositions.end())
            continue;
        else
            std::cout << "===== " << i << std::endl;
    }
}

/**
 * This function prints the game board.
 * @param board The game board.
 */
void MineSweeper::printGameBoard(std::string board[13][26]) {
//    std::cout << "====================================================\n\n";
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 26; j++) {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
}

/**
 * This function updates the players chosen position on the game board.
 * The position is added to the playerPositions vector to be stored.
 * @param position The position to be updated.
 */
void MineSweeper::updateGameBoard(int position) {
    std::string number = std::to_string(calculateNumberForBoard(position)); // Value will temporarily always be 1
    number = "\x1B[32m" + number + "\x1B[97m";

    playerPositions.push_back(position);
    positionsRemaining--;
    positionsOpened++;

    addToBoard(number, position);
    printGameBoard(gameBoard);
}

/**
 * This function is used to add the symbol passed is as a parameter to the position that is passed as a parameter to the game board.
 * @param symbol The symbol to add (X/1-9/blockCharacter).
 * @param position The position to add the symbol to.
 */
void MineSweeper::addToBoard(std::string symbol, int position) {
    switch (position) {
        case 1:
            gameBoard[2][4] = symbol;
            break;
        case 2:
            gameBoard[2][8] = symbol;
            break;
        case 3:
            gameBoard[2][12] = symbol;
            break;
        case 4:
            gameBoard[2][16] = symbol;
            break;
        case 5:
            gameBoard[2][20] = symbol;
            break;
        case 6:
            gameBoard[2][24] = symbol;
            break;
        case 7:
            gameBoard[4][4] = symbol;
            break;
        case 8:
            gameBoard[4][8] = symbol;
            break;
        case 9:
            gameBoard[4][12] = symbol;
            break;
        case 10:
            gameBoard[4][16] = symbol;
            break;
        case 11:
            gameBoard[4][20] = symbol;
            break;
        case 12:
            gameBoard[4][24] = symbol;
            break;
        case 13:
            gameBoard[6][4] = symbol;
            break;
        case 14:
            gameBoard[6][8] = symbol;
            break;
        case 15:
            gameBoard[6][12] = symbol;
            break;
        case 16:
            gameBoard[6][16] = symbol;
            break;
        case 17:
            gameBoard[6][20] = symbol;
            break;
        case 18:
            gameBoard[6][24] = symbol;
            break;
        case 19:
            gameBoard[8][4] = symbol;
            break;
        case 20:
            gameBoard[8][8] = symbol;
            break;
        case 21:
            gameBoard[8][12] = symbol;
            break;
        case 22:
            gameBoard[8][16] = symbol;
            break;
        case 23:
            gameBoard[8][20] = symbol;
            break;
        case 24:
            gameBoard[8][24] = symbol;
            break;
        case 25:
            gameBoard[10][4] = symbol;
            break;
        case 26:
            gameBoard[10][8] = symbol;
            break;
        case 27:
            gameBoard[10][12] = symbol;
            break;
        case 28:
            gameBoard[10][16] = symbol;
            break;
        case 29:
            gameBoard[10][20] = symbol;
            break;
        case 30:
            gameBoard[10][24] = symbol;
            break;
        case 31:
            gameBoard[12][4] = symbol;
            break;
        case 32:
            gameBoard[12][8] = symbol;
            break;
        case 33:
            gameBoard[12][12] = symbol;
            break;
        case 34:
            gameBoard[12][16] = symbol;
            break;
        case 35:
            gameBoard[12][20] = symbol;
            break;
        case 36:
            gameBoard[12][24] = symbol;
            break;
        default:
            break;
    }
}

int MineSweeper::calculateNumberForBoard(int position) {
    int bombsTouchingPosition{};

    for (int i = 1; i <= 36; i++) {

    }
    return bombsTouchingPosition;
}

/**
 * This function is used to reveal all of the bombs on the game board after the player has either won or lost the game.
 */
void MineSweeper::revealGameBoardWhenGameOver() {
    std::string bomb{"\x1B[91mX\x1B[97m"};

    for (int position : bombPositions)
        addToBoard(bomb, position);

    printGameBoard(gameBoard);
}

/**
 * This function handles the players move.
 * The row and column of the position chosen by the player are converted to a single number (1 through 36), so it can be
 * checked against the bomb positions.
 * @param row The row.
 * @param col The column.
 */
void MineSweeper::handlePlayerMove(int row, int col) {
    int positionToCheck{};
    if (row == 1) {
        if (col == 1)
            positionToCheck = 1;
        else if (col == 2)
            positionToCheck = 2;
        else if (col == 3)
            positionToCheck = 3;
        else if (col == 4)
            positionToCheck = 4;
        else if (col == 5)
            positionToCheck = 5;
        else if (col == 6)
            positionToCheck = 6;
    }
    else if (row == 2) {
        if (col == 1)
            positionToCheck = 7;
        else if (col == 2)
            positionToCheck = 8;
        else if (col == 3)
            positionToCheck = 9;
        else if (col == 4)
            positionToCheck = 10;
        else if (col == 5)
            positionToCheck = 11;
        else if (col == 6)
            positionToCheck = 12;
    }
    else if (row == 3) {
        if (col == 1)
            positionToCheck = 13;
        else if (col == 2)
            positionToCheck = 14;
        else if (col == 3)
            positionToCheck = 15;
        else if (col == 4)
            positionToCheck = 16;
        else if (col == 5)
            positionToCheck = 17;
        else if (col == 6)
            positionToCheck = 18;
    }
    else if (row == 4) {
        if (col == 1)
            positionToCheck = 19;
        else if (col == 2)
            positionToCheck = 20;
        else if (col == 3)
            positionToCheck = 21;
        else if (col == 4)
            positionToCheck = 22;
        else if (col == 5)
            positionToCheck = 23;
        else if (col == 6)
            positionToCheck = 24;
    }
    else if (row == 5) {
        if (col == 1)
            positionToCheck = 25;
        else if (col == 2)
            positionToCheck = 26;
        else if (col == 3)
            positionToCheck = 27;
        else if (col == 4)
            positionToCheck = 28;
        else if (col == 5)
            positionToCheck = 29;
        else if (col == 6)
            positionToCheck = 30;
    }
    else if (row == 6) {
        if (col == 1)
            positionToCheck = 31;
        else if (col == 2)
            positionToCheck = 32;
        else if (col == 3)
            positionToCheck = 33;
        else if (col == 4)
            positionToCheck = 34;
        else if (col == 5)
            positionToCheck = 35;
        else if (col == 6)
            positionToCheck = 36;
    }

    // If the position the player picked does not have a bomb
    if (!checkPlayerPosition(positionToCheck)) {
        updateGameBoard(positionToCheck);

        // Checking if the player has won
        if (positionsOpened == (36 - numberOfBombs))
            handleWin();
    }
    // If the position the player picked does have a bomb => Game Over
    else {
        revealGameBoardWhenGameOver();
        std::cout << "\nHard luck you've just exploded! Game Over!" << std::endl;
        std::cout << "Score: " << score << std::endl;
        this->gameRunning = false;
    }
}

/**
 * This function is called if the player has won the game and prints out a message.
 */
void MineSweeper::handleWin() {
    std::cout << green << "\nCongratulations You Win " << playerName << "!!!" << white << std::endl;
    std::cout << "Score: " << score << std::endl;
    revealGameBoardWhenGameOver();
    this->gameRunning = false;
}

/**
 * This function is used to reset the game if the player would like to play again.
 */
void MineSweeper::resetGame() {
    for (int i = 1; i <= 36; i++) {
        addToBoard(blockCharacter, i);
    }
    playerPositions.clear();
    bombPositions.clear();
    gameMode = idle;

    startGame();
}

/**
 * This function checks if the position the player picked contains a bomb or not.
 * @param position The position to be checked.
 * @return True if there is a bomb in that position, False otherwise.
 */
bool MineSweeper::checkPlayerPosition(int position) {
    if (std::find(bombPositions.begin(), bombPositions.end(), position) != bombPositions.end())
        return true;
    return false;
}

/**
 * This function prints out the instructions at the start of the game.
 */
void MineSweeper::printInstructions() {
    std::cout << underline << green << "\n=== Game Instructions ===" << white << removeUnderline << std::endl;
    std::cout << "- When you select the game mode, the bombs will be added to the board and it will be displayed like below." << std::endl;
    std::cout << "- When the game starts, each position will contains a \"\u2588\", which indicates an unopened position." << std::endl;
    std::cout << "- You will then be asked to enter the position you would like to reveal. To enter a position, you have to enter the row number \n"
                 "  followed by a space, followed by the column number." << std::endl;
    std::cout << "- For example, to reveal the very first position on the board, which is the first row and the first column, you would enter: 1 1." << std::endl;
    std::cout <<"- When you reveal a position, you will see either an \"" << red << "X" << white << "\", which indicates a bomb, or a number from 1 -> 9, depending on whether \n"
                "  there was a bomb in that position or not." << std::endl;
    std::cout << "- If you reveal a bomb (" << red << "X" << white "), the game is over!\n" << std::endl;

    printGameBoard(gameBoard);
}

/**
 * This function prints out all the current games details such as the positions opened, the positions remaining, the number of bombs
 * and the players current score.
 */
void MineSweeper::printGameDetails() const {
    std::cout << underline << "\nPositions Opened:" << removeUnderline << " " << positionsOpened
              << " | " << underline << "Positions Remaining:" << removeUnderline << " " << positionsRemaining
              << " | " << underline << "Number of Bombs:" << removeUnderline << " " << numberOfBombs
              << " | " << underline << "Score:" << removeUnderline << " " << score;
}






