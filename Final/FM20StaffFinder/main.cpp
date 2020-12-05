/**
 * main.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 * CS 151 3228 Final Project: Football Manager 20 Scout
 *
 */
#include <iostream>
#include "App.h"
#include "Person.h"
#include "Player.h"
using namespace std;


int main() {
    App app{};
    cout << "Welcome to FM20 Scouter! Compare two staff members or two players.\n";
    switch((app.getMenuOption())) {
        case 1:
            app.compareStaff();
            break;
        case 2:
            app.comparePlayers();
            break;
    }

//    Staff member("Germany", "Jurgen Klopp", 52, "Manager", "Liverpool");
//    member.setCoaching(16, 14, 16, 17, 15, 14, 16);
//    app.saveToFile(member);
//    app.addStaffFile();

    return 0;
}
