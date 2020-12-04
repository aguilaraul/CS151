/**
 * App.h
 * Author   Raul Aguilar
 * Date     December 3, 2020
 * CS 151 3228 Final Project
 */

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

private:
    Staff member1, member2;
    void inputStaffMembers();
    void inputPlayers();

    bool askToInputStaffMember();
    bool askToSaveToFile();

    Staff addStaffManual();
    Staff addStaffFile();

    void saveToFile(Staff&);

    bool validateAnswer();

    // Manual input
    void manualCoachingInput(Staff&);
    void inputMedical(Staff&);
    void inputGKCoaching(Staff&);
    void inputMental(Staff&);
    void inputScouting(Staff&);
    void inputKnowledge(Staff&);

    // Read from file
    void readCoachingAttributes(Staff, fstream&, long long&);
};


#endif //FM20SCOUT_APP_H
