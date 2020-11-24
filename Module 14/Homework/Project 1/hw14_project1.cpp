/**
 * hw14_project1.cpp
 * Raul Aguilar
 * November 23, 2020
 * CS 151 3228 Module 14 Homework 14
 * Design a LinkedList class
 *
 * Algorithm:
 * Algorithm for each function above each function heading
 */
#include <iostream>
#include "LinkedList.h"

int main() {
    // Create list and add 7.0, 8.0, 9.0
    LinkedList list;
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    // Testing isMember
    if(list.isMember(9.0)) {
        cout << 9.0 << " is in the list." << endl;
    }
    if(list.isMember(7.0)) {
        cout << 7.0 << " is in the list.";
    }
    if(list.isMember(5.0)) {
        cout << 5.0 << " is in the list.";
    }

    // Testing print()
    cout << "\nList: ";
    list.print();

    // Testing reverse()
    list.reverse();
    cout << "\nList Reversed: ";
    list.print();

    // Test search()
    cout << "\nPosition of 7.0: " << list.search(7.0);
    cout << "\nPosition of 5.0: " << list.search(5.0);



    return 0;
}
