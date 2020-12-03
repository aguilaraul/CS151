//
// Created by raula on 11/17/2020.
//

#ifndef FM20SCOUT_APP_H
#define FM20SCOUT_APP_H
#include "Staff.h"
#include <iostream>
#include <iomanip>

class App {
public:
    int getMenuOption();
    void inputStaffMembers();
    void inputPlayers();

//private:
    void compareStaff();
    void comparePlayers();

    Staff addStaffManual();
    Staff addStaffFile();

    void saveToFile(Staff);

    bool validateAnswer();

    // Manual input
    void manualCoachingInput(Staff);
    void inputMedical(Staff);
    void inputGKCoaching(Staff);
    void inputMental(Staff);
    void inputScouting(Staff);
    void inputKnowledge(Staff);

    // Read from file
    void readCoachingAttributes(Staff, fstream&, long long&);
};


#endif //FM20SCOUT_APP_H
