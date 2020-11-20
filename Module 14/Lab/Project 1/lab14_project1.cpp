/**
 * lab14_project1.cpp
 * Author:  Raul Aguilar
 * Date:    November 19, 2020
 * CS 151 3228 Module 14 Lab 14 Project 1
 * Using the LinkedList.h file below, add the following functions to
 * increase the usability of the class it contains
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> numbers;

    numbers.addFirst(45);
    numbers.addFirst(90);
    numbers.add(0, 100);
    numbers.add(4, 30);
    cout << "Starting list: ";
    numbers.display();
    cout << endl;

    // Testing remove()
    if(numbers.remove(45)) {
        cout << "\nAfter remove(45): ";
    }
    numbers.display();
    cout << endl;

    // Testing removeAt()
    try {
        cout << "\nremoveAt(2) value: " << numbers.removeAt(2);
        cout << "\nremoveAt(99) value: " << numbers.removeAt(99);
    } catch (runtime_error&) {
        cout << "Exception: Couldn't remove.";
    }
    cout << "\nAfter removeAt(2): ";
    numbers.display();
    cout << "\nSize: " << numbers.getSize();

    // Testing Set
    if(numbers.set(0, 200)) {
        cout << "\n\nAfter set(0, 200): ";
    }
    if(numbers.set(2, 444)) {
        cout << "\nAfter set(2, 444): ";
    }
    numbers.display();

    // Testing lastIndexOf()
    numbers.addLast(200);
    numbers.addLast(200);
    numbers.addLast(888);
    cout << "\n\nAfter adding 3 elements: ";
    numbers.display();
    cout << "\nlastIndexOf(200): " << numbers.lastIndexOf(200);
    cout << "\nlastIndexOf(45): " << numbers.lastIndexOf(45) << endl;

    // Testing contains()
    if(numbers.contains(200)) {
        cout << "\nList contains: 200";
    }

    // Testing empty display
    numbers.clear();
    cout <<"\n\nAfter clear(): ";
    numbers.display();


    return 0;
}
