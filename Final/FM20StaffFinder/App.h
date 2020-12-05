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
    int getMenuOption();
    void compareStaff();
    void comparePlayers();

private:
    void inputStaffMembers(Staff&, Staff&);
    void inputPlayers();

    void setStaffManual(Staff&);
    void addStaffFile(Staff&);

    void saveToFile(Staff&);

    bool validateAnswer();
    bool askToInputStaffMember();
    bool askToSaveToFile();

    // Manual input
    void manualCoachingInput(Staff&);
    void inputMedical(Staff&);
    void inputGKCoaching(Staff&);
    void inputMental(Staff&);
    void inputScouting(Staff&);
    void inputKnowledge(Staff&);

    // Compare
    void staffComparison(Staff&, Staff&);
};


#endif //FM20SCOUT_APP_H
