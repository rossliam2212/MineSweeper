#include <iostream>
#include <string>

#include "MineSweeper.h"

int main() {
    std::string name;
    std::cout << "Enter your name: \n>";
    std::getline(std::cin, name);

    MineSweeper game{name};
    game.startGame();

    bool quit{false};
    char playAgain;

    while (!quit) {
        std::cout << "\nWould you like to play again " << name << "? (y/n)\n>";
        std::cin >> playAgain;

        while (playAgain != 'y' && playAgain != 'n') {
            std::cout << "\nInvalid Choice! Try again! (y/n) \n>";
            std::cin >> playAgain;
        }

        if (playAgain == 'y') {
            game.resetGame();
        } else {
            std::cout << "\nThanks for playing " << name << "!" << std::endl;
            quit = true;
        }
    }

    return 0;
}
