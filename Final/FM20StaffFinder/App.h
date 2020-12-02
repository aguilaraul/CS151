//
// Created by raula on 11/17/2020.
//

#ifndef FM20SCOUT_APP_H
#define FM20SCOUT_APP_H
#include "Staff.h"
#include <iostream>
#include <iomanip>
#include <fstream>

class App {
public:
    int getMenuOption();
    void compareStaff();
    void comparePlayers();

    Staff addStaffManual();
    Staff addStaffFile();

    void saveToFile(Staff);

    bool validateAnswer();

    void inputCoaching(Staff);
    void inputMedical(Staff);
    void inputGKCoaching(Staff);
    void inputMental(Staff);
    void inputScouting(Staff);
    void inputKnowledge(Staff);
};


#endif //FM20SCOUT_APP_H
