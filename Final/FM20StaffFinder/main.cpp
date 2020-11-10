/**
 * main.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 3228 Final Project: Football Manager 20 Staff Finder
 *
 */
#include <iostream>
using namespace std;
#include "Person.h"
#include "Staff.h"
#include "Player.h"

int main() {
    string country = "Spain";
    string name = "Pep Guardiola";
    int age = 48;
    Person Pep(country, name, age);
    Staff Klopp("Germany", "Jurgen Klopp", 52, "Manager", "Liverpool");

    cout << Pep.to_string() << endl;
    cout << Klopp.to_string() << endl;
    Klopp.setClub("Real Madrid");
    cout << Klopp.to_string() << endl;

    Klopp.printAttributes();

    return 0;
}
