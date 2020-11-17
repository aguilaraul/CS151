/*
 * lab9_project1.cpp
 * Author:  Raul Aguilar
 * Date:    October 31, 2020
 *
 * CS 151 3228 Module 9 Lab 9 Project 1
 * Create a binary file consisting of 10 ints (1 - 10) and 10 doubles
 * (square roots)
 *
 */
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName = "array.dat";

    // Open ofstream variable for binary output
    ofstream data_file(fileName, ios::binary | ios::out);
    if(!data_file) {
        cout << "Failed to open output file. Program exiting.";
        exit(1);
    }

    // Write numbers from 1 to 10 as integers stored as binary numbers
    for(int i = 1; i <= 10; i++) {
        data_file.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    // Write the square roots of the numbers from 1-10 onto the same
    // file
    for(int i = 1; i <= 10; i++) {
        double sr = sqrt(i);
        data_file.write(reinterpret_cast<char*>(&sr), sizeof(double));
    }

    data_file.close();
    return 0;
}
