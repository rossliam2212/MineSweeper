//
// Created by Liam Ross on 18/01/2022.
//

#ifndef MINESWEEPER_WINTRACKER_H
#define MINESWEEPER_WINTRACKER_H

#include <string>

class WinTracker {
private:
    std::string playerName; // -- Player name variable may not be needed

    int oneBombWins;
    int threeBombWins;
    int fiveBombWins;
    int tenBombWins;
    int twentyBombWins;
    int thirtyFiveBombWins;

public:
    explicit WinTracker(std::string playerName);
    void printAllWins();

    // Update functions
    void updateOneBombWins();
    void updateThreeBombWins();
    void updateFiveBombWins();
    void updateTenBombWins();
    void updateTwentyBombWins();
    void updateThirtyFiveBombWins();

    // Getter functions
    int getOneBombWins() const;
    int getThreeBombWins() const;
    int getFiveBombWins() const;
    int getTenBombWins() const;
    int getTwentyBombWins() const;
    int getThirtyFiveBombWins() const;

};


#endif //MINESWEEPER_WINTRACKER_H
