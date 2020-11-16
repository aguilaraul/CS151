/**
 * hw8_project2.cpp
 * Author   Raul Aguilar
 * Date     November 15, 2020
 * CS 151 Module 8 Homework 8 Project 2
 * Write a program that asks for a password and then calls a function
 * which verifies that it meets the stated criteria.
 *
 * Algorithm:
 * 1. Input password from user
 * 2. Validate password
 *  a. Set up flags for each requirement
 *  b. If password if not 6+ characters long, mark flag false.
 *  Otherwise, true.
 *  c. Loop through each character in the password
 *  Check if current character is:
 *      - Uppercase
 *      - Lowercase
 *      - a digit
 *  d. Mark flags accordingly
 *  e. If any of the flags are false, check each individual flag to
 *  determine specifically which flag(s) are triggering false. Display
 *  error message according to each error flag. And return false.
 *  f. If no flags were triggered, password is valid - return true.
 */
#include <iostream>
using namespace std;

bool validPassword(const string&);

int main() {
    string password;

    cout << "Password must:\n"
         << "\t* Must be at least 6 characters long\n"
         << "\t* Must have at least 1 uppercase letter and 1 lowercase letter\n"
         << "\t* Must have at least 1 digit" << endl;
    cout << "Enter a password:\n";
    cin >> password;

    if(validPassword(password)) {
        cout << "Password accepted." << endl;
    } else {
        cout << "Invalid password. Please re-enter a new one." << endl;
    }

    return 0;
}

bool validPassword(const string& pw) {
    bool validLength, validUpper, validLower, validDigit;
    if(pw.length() >= 6) {
        validLength = true;
    } else {
        validLength = false;
    }
    for(char c:pw) {
        if(isupper(c)) {
            validUpper = true;
        }
        if(islower(c)) {
            validLower = true;
        }
        if(isdigit(c)) {
            validDigit = true;
        }
    }
    if(!validLength || !validUpper || !validLower | !validDigit) {
        if(!validLength) {
            cout << "Password must have at least 6 characters." << endl;
        }
        if(!validUpper) {
            cout << "Password must contain at least one uppercase letter." << endl;
        }
        if(!validLower) {
            cout << "Password must contain at least one lowercaser letter." << endl;
        }
        if(!validDigit) {
            cout << "Password must contain at least one digit." << endl;
        }
        return false;
    } else {
        cout << "Password is valid." << endl;
        return true;
    }
}