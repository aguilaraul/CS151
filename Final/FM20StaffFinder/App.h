/**
 * App.h
 * Author   Raul Aguilar
 * Date     December 3, 2020
 * CS 151 3228 Final Project
 */

#ifndef FM20SCOUT_APP_H
#define FM20SCOUT_APP_H
#include "Staff.h"
#include "Player.h"
#include <iostream>
#include <iomanip>

class App {
public:
    void run();

private:
    int getMenuOption();
    void compareStaff();
    void comparePlayers();

    void inputStaffMember(Staff&);
    void inputPlayer(Player&);

    void setStaffManual(Staff&);
    void setPlayerManual(Player&);

    void addStaffFromFile(Staff&);
    void addPlayerFromFile(Player&);

    void saveToFile(Staff&);
    void saveToFile(Player&);

    bool validateAnswer();
    bool askToInputStaffMember();
    bool askToSaveToFile();

    // Compare
    void staffComparison(Staff&, Staff&);
};


#endif //FM20SCOUT_APP_H
