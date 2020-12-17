/**
 * Main.cpp
 *
 * Author:  Raul Aguilar
 * Date:    December 16, 2020
 * CS 151 3228 Final Project: Football Manager 20 Compare
 * The attributes of a football player are key to how they can perform
 * on the pitch. Getting an understanding of the attributes can help
 * you to build up a picture of the type of player you’re looking at,
 * as well as their quality in comparison with the rest of their team.
 *
 * Algorithm:
 * 1. User chooses between comparing two staff members or two players
 * 2. After the user selects, they are presented with the choice to
 * enter the Player/Staff (Person) information manually or load in
 * binary file
 * 3. If the user elects to enter the Person manually, they are asked
 * to enter the Person's personal information and club info and then
 * asked to fill in their attributes. After which the user is able to
 * save the Person to a binary file for later use
 * 4. If the user selects to enter the Person via file, then they are
 * asked for the corresponding file name. The binary file is read in
 * and the Person's info and attributes are filled in accordingly
 * 5. After the first Person is loaded in, the user is asked
 * about the second Person in the same manner as step 2
 * 6. After both Persons are loaded, their attributes are compared to
 * show each category, the winner, and their winning attribute value.
 * After the Person with the most wins is declared the better Staff
 * member / Player
 */
#include <iostream>
#include "App.h"
using namespace std;


int main() {
    App app{};
    cout << "Welcome to FM20 Scouter! Compare two staff members or two players.\n";
    app.run();
}
