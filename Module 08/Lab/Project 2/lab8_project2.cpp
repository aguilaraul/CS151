/**
 * lab8_project2.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 3228 Module 8 Lab Project 2
 * Use several functions from the C++ string class to convert numbers.
 *
 */
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // Prompt user for number
    cout << "Please enter a number:" << endl;
    int original = 0;
    cin >> original;

    // Convert number to a string and print out
    string original_as_string = to_string(original) + " rah!";
    cout << "Number to string:\t" << original_as_string << endl;

    // Convert back to number and print
    istringstream inpstr(original_as_string);
    int original_copy;
    inpstr >> original_copy;
    cout << "String back to number:\t" << original_copy << endl;

    // Convert number to binary and print
    char *binary = new char[33];
    *(binary + 32) = '\0';
    int index = 32;
    do {
        *(binary + (--index)) = (char) (original_copy%2+'0');
        original_copy /= 2;
    } while(original_copy > 0);

    cout << "That number in binary:\t" << (binary + index) << endl;

    // Convert binary string back to decimal number
    original_copy = stoi((binary+index), nullptr, 2);
    cout << "Back to decimal:\t" << original_copy << endl;

    // Convert number to hexadecimal
    stringstream iostr;
    iostr << hex << original;
    cout << "The number in hex:\t" << iostr.str() << endl;

    // Convert back to decimal and print
    iostr >> hex >> original_copy;
    cout << "Back to decimal:\t" << original_copy << endl;

    return 0;
}
