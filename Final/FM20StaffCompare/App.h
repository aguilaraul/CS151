/**
 * App.h
 * Author   Raul Aguilar
 * Date     December 12, 2020
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
    ~App();

private:
    static int getMenuOption();
    void compareStaff();
    void comparePlayers();

    void inputStaffMember(Staff&);
    void inputPlayer(Player&);

    void setStaffManual(Staff&);
    void setPlayerManual(Player&);

    static void addStaffFromFile(Staff&);
    static void addPlayerFromFile(Player&);

    static void saveToFile(Staff&);
    static void saveToFile(Player&);

    static bool validateAnswer();
    static bool askToInputStaffMember();
    static bool askToSaveToFile();

    // Compare
    static void comparison(const Staff&, const Staff&);
    static void comparison(const Player&, const Player&);
};


#endif //FM20SCOUT_APP_H
