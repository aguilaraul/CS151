/**
 * hw13_project1.cpp
 * Author   Raul Aguilar
 * Date     November 18, 2020
 * CS 151 3228 Module 13 Homework 13 Project 1
 * Write a class BCheckString that is derived from the STL string class
 * that accepts a string into its constructor, and overrides []operator
 * to throw BoundsException if [int k] is out of range of string.
 *
 * Algorithm:
 * If k < 0 or k > string length, then throw BoundsException explaining
 * that index chosen is out of bounds. Otherwise return the character
 * at the index provided.
 */
#include <iostream>
using namespace std;

class BCheckString : public string {
public:
    BCheckString(string str): string(move(str)) {}
    char operator[](int k) {
        if(k < 0 || k > this->length()) {
            throw BoundsException();
        }
        return this->at(k); // Throws its own exception if out of range
    }
    class BoundsException { // Exception class
    public:
        BoundsException() = default;
    };
};

int main() {
    BCheckString string1("Hello World!");

    try {
        cout << string1[4] << endl;
        cout << string1[100] << endl;
    }catch(BCheckString::BoundsException) {
        cout << "BoundsException: Out of Bounds.\n";
    }

    return 0;
}
