/**
 * lab11_project1.cpp
 * Author:  Raul Aguilar
 * Date:    November 11, 2020
 *
 * CS 151 3228 Module 11 Lab 11 Project 1
 * Create two functions (one recursive, one iterative) which take a
 * non-negative whole number (in decimal as specified in your C++
 * source code) and convert it to a string of 0’s and 1’s representing
 * the same number in binary (base 2).
 *
 * Algorithm:
 *  Iterative
 * While decimal (n) is greater than 0, keep appending the remainder of
 * n/2 to a binary string and set n = n/2
 *  Recursive
 * Base case: If n == 0, return binary string
 * Else, append remainder of n/2 to binary string and run again
 * with n/2
 */
#include <iostream>
using namespace std;

string decimalToBinaryIterative(int);
string decimalToBinaryRecursive(int);
string decimalToBinaryRecursiveHelper(int, string);

int main() {
    int decimal = 0;
    cout << "Enter a decimal to convert to binary:\n";
    cin >> decimal;

    string binary = decimalToBinaryIterative(decimal);
    string binaryR = decimalToBinaryRecursive(decimal);

    cout << "Iterative:\n"
         << decimal << " in binary is: " << binary << endl;
    cout << "Recursive:\n"
         << decimal << " in binary is: " << binaryR << endl;

    return 0;
}

// Iterative
string decimalToBinaryIterative(int n) {
    string binary;
    do {
        binary = to_string(n%2) + binary;
        n/=2;
    } while(n > 0);
    return binary;
}

// Recursive
string decimalToBinaryRecursive(int n) {
    if(n == 0) { return "0"; }
    string binary;
    return decimalToBinaryRecursiveHelper(n, binary);
}

string decimalToBinaryRecursiveHelper(int n, string s) {
    if(n == 0) {
        return s;
    }
    s = to_string(n%2) + s;
    return decimalToBinaryRecursiveHelper(n / 2, s);
}