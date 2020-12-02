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
//    switch((app.getMenuOption())) {
//        case 1:
//            app.compareStaff();
//            break;
//        case 2:
//            app.comparePlayers();
//            break;
//    }

    Staff member("Spain", "Pep Guardiola", 48, "Manager", "Manchester City");
    app.saveToFile(member);

    return 0;
}
