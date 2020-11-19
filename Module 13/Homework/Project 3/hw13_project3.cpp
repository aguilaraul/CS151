/**
 * hw13_project3.cpp
 * Author:  Raul Aguilar
 * Date:    November 19, 2020
 * CS 151 3228 Module 13 Homework 13 Project 3
 * Write a class template named SortableVector. The class should be
 * derived from the SimpleVector class presented in this chapter. It
 * should have a member function that sorts the array elements in
 * ascending order.
 */
#include <iostream>
#include "SortableVector.h"
using namespace std;

template<class T>
void printVector(SimpleVector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    SortableVector<double> numbers(10);

    // Fill and print array with doubles
    cout << "Double Vector:\n";
    for(int i = 0; i < 10; i++) {
        numbers.push_back((rand() % 100)* 3.14) ;
        cout << numbers[i] << " ";
    }
    cout << endl;

    numbers.sort(numbers);

    // Print sorted vector
    cout << "Double Vector After Sorting:\n";
    printVector(numbers);


    return 0;
}
