//
// Created by Liam Ross on 18/01/2022.
//

#ifndef MINESWEEPER_WINTRACKER_H
#define MINESWEEPER_WINTRACKER_H

#include <string>

class WinTracker {
private:
    int oneBombWins;
    int threeBombWins;
    int fiveBombWins;
    int tenBombWins;
    int twentyBombWins;
    int thirtyFiveBombWins;

public:
    WinTracker();
    void printAllWins() const;

    // Update functions
    void updateOneBombWins();
    void updateThreeBombWins();
    void updateFiveBombWins();
    void updateTenBombWins();
    void updateTwentyBombWins();
    void updateThirtyFiveBombWins();
};


#endif //MINESWEEPER_WINTRACKER_H
