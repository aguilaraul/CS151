/**
 * lab8_project1.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 3228 Module 8 Lab Project 1
 * Encrypt a string using a lambda function.
 *
 */
#include <iostream>
#include <algorithm>
#include <strings.h>
using namespace std;

void encrypt(char& c) {
    if(isalnum(c)) {
        if(c == 'z') {
            c = 'a';
        } else if(c == 'Z') {
            c = 'A';
        } else if(c == '9') {
            c = '0';
        } else {
            c++;
        }
    }
}

int main() {
    string input;
    string test;

    cout << "Enter a string to encrypt:" << endl;
    getline(cin, input);

    test = input;
    for_each(test.begin(), test.end(),
             [](char &c) { c = tolower(c); } );

    while(test != "quit") {
        cout << input << endl;
        for_each(input.begin(), input.end(),
                 [](char &c) { encrypt(c); } );

        cout << input << endl;

        cout << "\nEnter a string to encrypt:" << endl;
        getline(cin, input);

        test = input;
        for_each(test.begin(), test.end(),
                 [](char &c) { c = tolower(c); } );
    }

    cout << "Program exiting..." << endl;
    exit(0);
    return 0;
}
