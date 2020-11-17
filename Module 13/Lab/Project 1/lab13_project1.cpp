/**
 * lab13_project1.cpp
 * Author   Raul Aguilar
 * Date     November 16, 2020
 * CS 151 3228 Module 13 Lab 13 Project 1
 * Write a function that accepts an integer parameter and returns its
 * integer square root (if it exists). The function should throw an
 * exception if it is passed an integer that is not a perfect square.
 * 
 * Algorithm:
 * 1. Create SquareRoot class that can hold a square root, and function
 * that can compute the square root of number passed into it.
 * 2. Create an exception class within SquareRoot that gets called when
 * a number is not a perfect square root and returns the value.
 * 3. Loop between number 0 through 25 to determine which are perfect
 * squares.
 */
#include <iostream>
#include <math.h>
using namespace std;

class SquareRoot {
    private:
    double sqRt;
    public:
    class NotASquareRoot { // Exception class
        public:
        int num;
        NotASquareRoot(int n) {
            num = n;
        }
    };
    double squareRoot(int num) {
        sqRt = sqrt(num);
        if(sqRt - (int)sqRt != 0) {
            throw NotASquareRoot(num);
        }
        return sqRt;
    }
};

int main() {
    SquareRoot sR{};

    for(int i = 0; i < 26; i++) {
        try {
            double sqRt = sR.squareRoot(i);
            cout << "Square root of " << i << " is " << sqRt << ". ";
            cout << i << " is a perfect square." << endl;
        } catch(SquareRoot::NotASquareRoot &nSqRt) {
            cout << nSqRt.num << " is not a perfect square." << endl;
        }
    }

    return 0;
}