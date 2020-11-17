/*
 * lab9_project2.cpp
 * Author:  Raul Aguilar
 * Date:    October 31, 2020
 *
 * CS 151 3228 Module 9 Lab 9 Project 2
 * Multiply every number in the file by a fixed amount
 *
 */
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName = "array.dat";

    // Open binary file for both input and output
    fstream data_file(fileName, ios::binary | ios::in | ios::out);
    if(!data_file) {
        cout << "Failed to open output file. Program exiting.";
        exit(1);
    }

    cout << "Enter a multiplier: ";
    double multiplier;
    cin >> multiplier;

    // Read integers from file, display on screen, multiply by the
    // multiplier, and write back out onto the file
    cout << "Reading and updating ints..." << endl;
    for(int i = 1; i <= 10; i++) {
        int data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast<char*>(&data), sizeof(int));
        cout << data << " -> ";
        data = round(data*multiplier);
        cout << data << endl;
        data_file.seekp(position, ios::beg); // write updated number
        data_file.write(reinterpret_cast<char*>(&data), sizeof(int));
    }

    // Read doubles from file, display, multiply, and write to file
    cout << "\nReading and updating doubles..." << endl;
    for(int i = 1; i <= 10; i++) {
        double data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast<char*>(&data), sizeof(double));
        cout << data << " -> ";
        data = data*multiplier;
        cout << data << endl;
        data_file.seekp(position, ios::beg);
        data_file.write(reinterpret_cast<char*>(&data), sizeof(double));
    }

    data_file.close();
    return 0;
}