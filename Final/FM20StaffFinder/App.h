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
    void compareStaff();
    void comparePlayers();

    Staff addStaffManual();
    Staff addStaffFile();
};


#endif //FM20SCOUT_APP_H
