/**
 * hw8_project3.cpp
 * Author:  Raul Aguilar
 * Date:    November 15, 2020
 * CS 151 3228 Module 8 Homework 8 Project 3
 * Create a searchable database that retrieves all matching names or
 * partial name.
 *
 * Algorithm:
 * 1. Get name from user
 * 2. Loop through each person in array. If current person is contains
 * the user name, print out person details and set nameFound to true.
 * Otherwise, move on to next person.
 * 3. If nameFound was not set to true, print out message stating that
 * name was not found array.
 */
#include <iostream>
using namespace std;

int main() {
    string phoneBook[] = {
            "Hoshikawa Tanaka, 678-1223",
            "Joe Looney, 586-0097",
            "Geri Palmer, 223-8787",
            "Lynn Lopez, 887-1212",
            "Holly Gaddis, 223-8878",
            "Julio Reyes, 486-0998",
            "Bob Kain 586-8712",
            "Jacques Franc, 586-7676",
            "Warren Glover, 223-9037",
            "Jeane Rodriquez, 678-4939",
            "Ron Palmer, 486-2783"
    };

    // Get name from user
    string name;
    cout << "Enter a name to search:\n";
    getline(cin, name);
    
    // Set nameFound to false, only way to trigger true if there is
    // at least one match
    bool nameFound = false;
    for(string &person:phoneBook) {
        if(person.find(name) != -1) {
            cout << person << endl;
            nameFound = true;
        }
    }
    
    // Print if name was not found
    if(!nameFound) {
        cout << name << " was not found." << endl;
    }

    return 0;
}
