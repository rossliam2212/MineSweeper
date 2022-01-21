//
// Created by Liam Ross on 18/01/2022.
//

#include <iostream>
#include <utility>
#include "MineSweeper.h"

#define underline "\033[4m" // Add underline to text
#define removeUnderline "\033[0m" // Remove underline from text
#define green "\x1B[32m" // Make text green
#define red "\x1B[31m" // Make text red
#define white "\x1B[97m" // Make text white

MineSweeper::MineSweeper(std::string name) :
      playerName{std::move(name)},
      gameRunning{false},
      board{},
      gameMode{idle},
      score{0},
      winTracker{name} {
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
        std::cout << underline << green << "\n=== Game Started. Good Luck! ===\n" << white << removeUnderline <<  std::endl;
        board.printGameBoard();

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

    int option{};

    while (option != 1) {
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "\t1 - Play Mine Sweeper" <<
                     "\n\t2 - View previous game wins" << std::endl;
        std::cin >> option;

        while (!std::cin && option < 1 && option > 2) {
            std::cout << "Sorry that's not an option! Try again! \n>";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> option;
        }

        switch (option) {
            case 1:
                handleGameMode();
                break;
            case 2:
                winTracker.printAllWins();
                break;
            default:
                break;
        }
    }
}

void MineSweeper::handleGameMode() {
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
            board.setNumberOfBombs(1);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " One Bomb" << std::endl;
            break;
        case 3:
            gameMode = threeBomb;
            board.setNumberOfBombs(3);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Three Bombs" << std::endl;
            break;
        case 5:
            gameMode = fiveBomb;
            board.setNumberOfBombs(5);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Five Bombs" << std::endl;
            break;
        case 10:
            gameMode = tenBomb;
            board.setNumberOfBombs(10);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Ten Bombs" << std::endl;
            break;
        case 20:
            gameMode = twentyBomb;
            board.setNumberOfBombs(20);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Twenty Bombs" << std::endl;
            break;
        case 35:
            gameMode = thirtyFiveBomb;
            board.setNumberOfBombs(35);
            std::cout << underline << "\nGame mode chosen:" << removeUnderline << " Thirty Five Bombs" << std::endl;
            break;
        default:
            return false;
    }
    board.placeBombsOnBoard();
    return true;
}

/**
 * This function updates the players chosen position on the game board.
 * The position is added to the playerPositions vector to be stored.
 * @param position The position to be updated.
 */
void MineSweeper::setPlayerPosition(int position) {
    std::string number = std::to_string(calculateNumberForBoard(position)); // Value will temporarily always be 1
    number = "\x1B[32m" + number + "\x1B[97m";

    board.updatePlayerPositions(position);
    board.updatePositionsRemaining();
    board.updatePositionsOpened();

    board.addToBoard(number, position);
    board.printGameBoard();
}

int MineSweeper::calculateNumberForBoard(int position) {
    int bombsTouchingPosition{};
    std::vector<int> positionsToCheck = board.getPositionSurroundings().at(position-1);

    for (int i = 0; i < board.getBombPositions().size(); i++) {
        for (int j = 0; j < positionsToCheck.size(); j++) {
            if (board.getBombPositions().at(i) == positionsToCheck.at(j))
                bombsTouchingPosition++;
        }
    }
    std::cout << "\nBombs Touching position: " << bombsTouchingPosition << "\n" << std::endl;
    return bombsTouchingPosition;

    return 1; // Temporarily return 1
}

/**
 * This function handles the players move.
 * The row and column of the position chosen by the player are converted to a single number (1 through 36), so it can be
 * checked against the bomb positions.
 * @param row The row.
 * @param col The column.
 */
void MineSweeper::handlePlayerMove(int row, int col) {
    int position{};
    if (row == 1) {
        if (col == 1)
            position = 1;
        else if (col == 2)
            position = 2;
        else if (col == 3)
            position = 3;
        else if (col == 4)
            position = 4;
        else if (col == 5)
            position = 5;
        else if (col == 6)
            position = 6;
    }
    else if (row == 2) {
        if (col == 1)
            position = 7;
        else if (col == 2)
            position = 8;
        else if (col == 3)
            position = 9;
        else if (col == 4)
            position = 10;
        else if (col == 5)
            position = 11;
        else if (col == 6)
            position = 12;
    }
    else if (row == 3) {
        if (col == 1)
            position = 13;
        else if (col == 2)
            position = 14;
        else if (col == 3)
            position = 15;
        else if (col == 4)
            position = 16;
        else if (col == 5)
            position = 17;
        else if (col == 6)
            position = 18;
    }
    else if (row == 4) {
        if (col == 1)
            position = 19;
        else if (col == 2)
            position = 20;
        else if (col == 3)
            position = 21;
        else if (col == 4)
            position = 22;
        else if (col == 5)
            position = 23;
        else if (col == 6)
            position = 24;
    }
    else if (row == 5) {
        if (col == 1)
            position = 25;
        else if (col == 2)
            position = 26;
        else if (col == 3)
            position = 27;
        else if (col == 4)
            position = 28;
        else if (col == 5)
            position = 29;
        else if (col == 6)
            position = 30;
    }
    else if (row == 6) {
        if (col == 1)
            position = 31;
        else if (col == 2)
            position = 32;
        else if (col == 3)
            position = 33;
        else if (col == 4)
            position = 34;
        else if (col == 5)
            position = 35;
        else if (col == 6)
            position = 36;
    }

    // If the position the player picked does not have a bomb
    if (!board.checkPlayerPositions(position)) {
        setPlayerPosition(position);

        // Checking if the player has won
        if (board.getPositionsOpened() == (36 - board.getNumberOfBombs()))
            handleWin();
    }
    // If the position the player picked does have a bomb => Game Over
    else {
        board.revealBoardWhenGameOver();
        std::cout << red <<  "\nHard luck " << playerName << "you've just exploded! Game Over!" << white << std::endl;
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

    std::cout << "\nHere were the bomb positions:" << std::endl;
    board.revealBoardWhenGameOver();
    updatePlayerWins();
    this->gameRunning = false;
}

void MineSweeper::updatePlayerWins() {
    switch (gameMode) {
        case oneBomb:
            winTracker.updateOneBombWins();
            break;
        case threeBomb:
            winTracker.updateThreeBombWins();
            break;
        case fiveBomb:
            winTracker.updateFiveBombWins();
            break;
        case tenBomb:
            winTracker.updateTenBombWins();
            break;
        case twentyBomb:
            winTracker.updateTwentyBombWins();
            break;
        case thirtyFiveBomb:
            winTracker.updateThirtyFiveBombWins();
            break;
        case idle:
            break;
    }
}

/**
 * This function is used to reset the game if the player would like to play again.
 */
void MineSweeper::resetGame() {
    board.resetGameBoard();
    gameMode = idle;
    startGame();
}

/**
 * This function prints out the instructions at the start of the game.
 */
void MineSweeper::printInstructions() {
    std::cout << underline << green << "\n=== Game Instructions ===" << white << removeUnderline << std::endl;
    std::cout << "- When you select the game mode, the bombs will be added to the board and it will be displayed like below." << std::endl;
    std::cout << "- When the game starts, each position will contains a \"" << blockCharacter << "\", which indicates an unopened position." << std::endl;
    std::cout << "- You will then be asked to enter the position you would like to reveal. To enter a position, you have to enter the row number \n"
                 "  followed by a space, followed by the column number." << std::endl;
    std::cout << "- For example, to reveal the very first position on the board, which is the first row and the first column, you would enter: 1 1." << std::endl;
    std::cout <<"- When you reveal a position, you will see either an \"" << red << "X" << white << "\", which indicates a bomb, or a number from 1 -> 9, depending on whether \n"
                "  there was a bomb in that position or not." << std::endl;
    std::cout << "- If you reveal a bomb (" << red << "X" << white "), the game is over!\n" << std::endl;

    board.printGameBoard();
}

/**
 * This function prints out all the current games details such as the positions opened, the positions remaining, the number of bombs
 * and the players current score.
 */
void MineSweeper::printGameDetails() const {
    std::cout << underline << "\nPositions Opened:" << removeUnderline << " " << board.getPositionsOpened()
              << " | " << underline << "Positions Remaining:" << removeUnderline << " " << board.getPositionsRemaining()
              << " | " << underline << "Number of Bombs:" << removeUnderline << " " << board.getNumberOfBombs()
              << " | " << underline << "Score:" << removeUnderline << " " << score;
}