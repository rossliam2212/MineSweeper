#include <iostream>
#include <string>

#include "MineSweeper.h"

int main() {
    std::string name;
    std::cout << "Enter your name: \n>";
    std::getline(std::cin, name);

    MineSweeper game{name};
    game.startGame();

//    int test[] {1, 2, 3};
//    int test1[] {6, 7, 8};
//
//    memset(test, 0, sizeof (test));
//    test = test1;

    return 0;
}
