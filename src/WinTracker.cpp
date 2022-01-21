//
// Created by Liam Ross on 18/01/2022.
//

#include <iostream>
#include <iomanip>
#include "WinTracker.h"

WinTracker::WinTracker(std::string playerName) :
    oneBombWins{0},
    threeBombWins{0},
    fiveBombWins{0},
    tenBombWins{0},
    twentyBombWins{0},
    thirtyFiveBombWins{0} {
}

void WinTracker::printAllWins() {
    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "| Game Mode" << std::setw(12) << " |  " << "Wins |" << std::endl;
    std::cout << "--------------------+--------" << std::endl;

    std::cout << "| One Bomb" << std::setw(13) << " |  " << oneBombWins << " |" << std::endl;
    std::cout << "| Three Bombs" << std::setw(10) << " |  " << threeBombWins << " |"  << std::endl;
    std::cout << "| Five Bombs" << std::setw(11) << " |  " << fiveBombWins << " |" << std::endl;
    std::cout << "| Ten Bombs" << std::setw(12) << " |  " << tenBombWins << " |" << std::endl;
    std::cout << "| Twenty Bombs" << std::setw(9) << " |  " << twentyBombWins << " |" << std::endl;
    std::cout << "| Thirty Five Bombs" << std::setw(3) << " |  " << thirtyFiveBombWins << " |" << std::endl;

    std::cout << "-----------------------------" << std::endl;
}


void WinTracker::updateOneBombWins() { oneBombWins++; }
void WinTracker::updateThreeBombWins() { threeBombWins++; }
void WinTracker::updateFiveBombWins() { fiveBombWins++; }
void WinTracker::updateTenBombWins() { tenBombWins++; }
void WinTracker::updateTwentyBombWins() { twentyBombWins++; }
void WinTracker::updateThirtyFiveBombWins() {thirtyFiveBombWins++; }

int WinTracker::getOneBombWins() const { return oneBombWins; }
int WinTracker::getThreeBombWins() const { return threeBombWins; }
int WinTracker::getFiveBombWins() const { return fiveBombWins; }
int WinTracker::getTenBombWins() const { return tenBombWins; }
int WinTracker::getTwentyBombWins() const { return twentyBombWins; }
int WinTracker::getThirtyFiveBombWins() const {return thirtyFiveBombWins; }
