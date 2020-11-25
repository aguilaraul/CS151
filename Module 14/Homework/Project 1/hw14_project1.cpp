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
    cout << "\n\nList Reversed: ";
    list.print();

    // Test search()
    cout << "\n\nPosition of 7.0: " << list.search(7.0);
    cout << "\nPosition of 5.0: " << list.search(5.0);

    // Testing insert()
    cout << "\n\nInsert 6.0 in pos 0:";
    list.insert(6.0, 0);
    cout << "\n";
    list.print();

    cout << "\n\nInsert 7.5 in pos 2:";
    list.insert(7.5, 2);
    cout << "\n";
    list.print();

    cout << "\n\nInsert 10.0 in pos 5:";
    list.insert(10.0, 5);
    cout << "\n";
    list.print();

    cout << "\n\nInsert 12.0 in pos 7:";
    list.insert(12.0, 7);
    cout << "\n";
    list.print();

    return 0;
}
