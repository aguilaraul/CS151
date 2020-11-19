/**
 * hw13_project2.cpp
 * Author:  Raul Aguilar
 * Date:    November 18, 2020
 * CS 151 3228 Module 13 Homework 13 Project 2
 * Modify the SimpleVector class template presented in this chapter, to
 * include the member functions push_back and pop_back.
 *
 * Algorithm for push_back:
 * If increasing size by 1 surpasses the current capacity, then throw
 * ArrayFullException. Otherwise, increment size by 1 and set index to
 * value/object passed.
 * Algorithm for pop_back:
 * If arraySize == 0, then throw ArrayEmptyException. Otherwise,
 * decrement the arraySize by 1.
 */
#include <iostream>
#include "SimpleVector.h"
using namespace std;

template<class T>
void printVector(SimpleVector<T> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    SimpleVector<int> numbers(4);
    try {
        numbers.push_back(3);
        numbers.push_back(5);
        numbers.push_back(6);
        numbers.push_back(12);
        cout << "Vector: ";
        printVector(numbers);
        numbers.push_back(19);
    } catch (SimpleVector<int>::ArrayFullException) {
        cout << "Cannot add element because vector is full." << endl;
    }

    try {
        numbers.pop_back();
        numbers.pop_back();
        numbers.pop_back();
        numbers.pop_back();
        cout << "Vector: ";
        printVector(numbers);
        numbers.pop_back();
    } catch (SimpleVector<int>::ArrayEmptyException) {
        cout << "Cannot remove the last element because vector is empty." << endl;
    }


    return 0;
}
