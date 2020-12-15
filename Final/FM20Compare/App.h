/**
 * App.h
 * Author   Raul Aguilar
 * Date     December 12, 2020
 * CS 151 3228 Final Project
 */

#ifndef FM20COMPARE_APP_H
#define FM20COMPARE_APP_H
#include "Staff.h"
#include "Player.h"
#include "AttributeRange.h"
#include <iostream>
#include <iomanip>

class App {
public:
    void run();

private:
    static int getMenuOption();
    static bool askToLoadPerson(const string &type);
    static bool askToSaveToFile();
    static bool validateAnswer();

    void compareStaff();
    void comparePlayers();
    template<class T> void comparison(const T&, const T&);

    void addStaffMember(Staff&);
    void addPlayer(Player&);

    void setStaffManual(Staff&);
    template<class T> void inputPersonalInfo(T&);
    static void inputCoaching(Staff&);
    static void inputMedical(Staff&);
    static void inputGKCoaching(Staff&);
    static void inputMental(Staff&);
    static void inputScouting(Staff&);
    static void inputKnowledge(Staff&);

    void setPlayerManual(Player&);
    void inputTechnical(Player&);
    void inputMental(Player&);
    void inputPhysical(Player&);

    // File operations
    template<class T> void loadFromFile(T&);
    template<class T> void saveToFile(T&);
};

#endif //FM20COMPARE_APP_H
