/**
 * hw8_project1.cpp
 * Author   Raul Aguilar
 * Date     November 15, 2020
 * CS 151 3228 Module 8 Homework 8 Project 1
 * Write a function that accepts a C-string as an argument and returns
 * the number of words contains in the string.
 *
 * Algorithm:
 *
 */
#include <iostream>
using namespace std;



int main() {
    const int SIZE = 241;
    char *line = new char[SIZE];

    // Get line from user
    cout << "Enter a sentence to count the words:\n";
    cin.getline(line, SIZE);



    return 0;
}
