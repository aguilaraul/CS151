/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     November 17, 2020
 * CS 151 3228 Final Project
 */
#include "App.h"
#include <iostream>
using namespace std;

int App::getMenuOption() {
    cout << "1. Compare two staff members\n"
         << "2. Compare two players\n";
    cout << "Select an option:" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Compare two staff members\n"
             << "2. Compare two players\n";
        cin >> choice;
    }
    return choice;
}

void compareStaff() {

}

void comparePlayers() {

}