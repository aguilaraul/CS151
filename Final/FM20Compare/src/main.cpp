/**
 * main.cpp
 *
 * Author:  Raul Aguilar
 * Date:    December 14, 2020
 * CS 151 3228 Final Project: Football Manager 20 Compare
 * The attributes of a football player are key to how they can perform
 * on the pitch. Getting an understanding of the attributes can help
 * you to build up a picture of the type of player you’re looking at,
 * as well as their quality in comparison with the rest of their team.
 */
#include <iostream>
#include "App.h"
using namespace std;


int main() {
    App app{};
    cout << "Welcome to FM20 Scouter! Compare two staff members or two players.\n";
    app.run();
}
