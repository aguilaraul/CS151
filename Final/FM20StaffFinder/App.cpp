/**
 * App.cpp
 * Author   Raul Aguilar
 * Date     November 17, 2020
 * CS 151 3228 Final Project
 */
#include "App.h"
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

void App::compareStaff() {
    Staff member1, member2;
    cout << "How would you like to load in the staff member?\n";
    cout << "1. Enter manually\n"
         << "2. Load a file\n";
    cout << "Select an option:" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Invalid menu option. Please make a different selection.\n";
        cout << "1. Enter manually\n"
             << "2. Load a file\n";
        cin >> choice;
    }
    if(choice == 1) {
        member1 = addStaffManual();
    } else {
        member1 = addStaffFile();
    }

    member1.printAttributes();
}

void App::comparePlayers() {

}

Staff App::addStaffManual() {
    string nation, name, role, club;
    int age;
    cout << "Enter the following information about the staff member:\n";
    cout << setw(20) << left << "Nation:";
    cin.ignore();
    getline(cin, nation);
    cout << "\nName:";
    getline(cin, name);
    cout << "\nAge:";
    cin >> age;
    cout << "\nRole:";
    cin.ignore();
    getline(cin, role);
    cout << "Club:";
    getline(cin, club);
    return Staff(nation, name, age, role, club);
}

Staff App::addStaffFile() {
    return {};
}