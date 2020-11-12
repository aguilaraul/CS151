/**
 * lab11_project2.cpp
 * Author:  Raul Aguilar
 * Date:    November 11, 2020
 * CS 151 3228 Module 11 Lab 11 Project 2
 * create two functions (one recursive, the other iterative) which take
 * a string of 0’s and 1’s, and return an int with its decimal
 * equivalent.
 *
 * Algorithm:
 *
 */
#include <iostream>
using namespace std;

int binaryToDecimalIterative(string);
int binaryToDecimalRecursive(string);
int binaryToDecimalRecursiveHelper(string, int);

int main() {
    string binary;
    cout << "Enter a binary number to convert to decimal:\n";
    cin >> binary;

    // Convert
    int decimal1 = binaryToDecimalIterative(binary);
    int decimal2 = binaryToDecimalRecursive(binary);

    // Display
    cout << "Iterative:\n"
         << binary << " to decimal is: " << decimal1 << endl;
    cout << "Recursive:\n"
         << binary << " to decimal is: " << decimal2 << endl;

    return 0;
}

//Iterative
int binaryToDecimalIterative(string binary) {
    int sum = (unsigned char)(binary[0]-'0');
    for(int i = 1; i < binary.size(); i++) {
        sum = (sum*2) + (unsigned char)(binary[i]-'0');
    }
    return sum;
}

// Recursive
int binaryToDecimalRecursive(string binary) {
    int sum = (unsigned char)(binary[0]-'0');
    return binaryToDecimalRecursiveHelper(binary.substr(1), sum);
}

int binaryToDecimalRecursiveHelper(string bin, int sum) {
    if(bin.length() == 0) {
        return sum;
    }
    sum = (sum*2) + (unsigned char)(bin[0]-'0');
    return binaryToDecimalRecursiveHelper(bin.substr(1), sum);
}