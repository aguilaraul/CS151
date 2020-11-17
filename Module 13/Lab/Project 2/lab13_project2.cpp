/**
 * lab13_project2.cpp
 * Author:  Raul Aguilar
 * Date:    November 16, 2020
 * CS 151 Module 13 Lab 13 Project 2
 * Write a function that forms and returns the sum of all items in the
 * vector v passed to it.
 *
 * Algortim:
 *
 */
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <class T>
T accum(vector<T> v) {
    T sum = T();
    for(auto &e:v) {
        sum += e;
    }
    return sum;
}


int main() {
    srand(time(nullptr));

    // Display all the vectors before summation
    cout << "Integer vector:\n";
    vector<int> intVector(5);
    for(int &i:intVector) {
        i = rand() % RAND_MAX;
        cout << i << " ";
    }
    cout << endl;

    vector<double> dVector = {1.13509, 2.73096, 3.676445, 4.94518, 5.74412};
    cout << "Double vector:\n";
    for(double &d:dVector) {
        cout << d << " ";
    }
    cout << endl;

    vector<string> strVector = {"Cause", "we", "found", "that", "beat"};
    cout << "String vector:\n";
    for(string &s:strVector) {
        cout << s << " ";
    }
    cout << endl << endl;

    // Print out summations
    cout << "Integer total:\n"
         << accum(intVector) << endl;
    cout << "Double total:\n"
         << accum(dVector) << endl;
    cout << "String total:\n"
         << accum(strVector) << endl;

    return 0;
}
