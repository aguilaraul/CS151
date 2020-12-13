/**
 * main.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 * CS 151 3228 Final Project: Football Manager 20 Scouter
 */
#include <iostream>
#include "App.h"
using namespace std;


int main() {
    App app{};
    cout << "Welcome to FM20 Scouter! Compare two staff members or two players.\n";
    app.run();
}
