/**
 * lab15_project1.cpp
 * Author:  Raul Aguilar
 * Date:    November 24, 2020
 * CS 151 3228 Module 15 Lab 15 Project 1
 * Enhance the Set class.
 */

#include <iostream>
#include "SetLinkedList.h"
using namespace std;

int main()
{
    /** Case 1 **/
    cout << "/--- CASE 1 ---/" << endl;
    Set<char> charSetA;
    charSetA.insert('C');
    charSetA.insert('G');
    charSetA.insert('E');
    charSetA.insert('A');
    cout << "charSetA: ";
    charSetA.display();

    Set<char> charSetB;
    charSetB.insert('E');
    charSetB.insert('C');
    charSetB.insert('F');
    cout << "charSetB: ";
    charSetB.display();

    // charSetA & charSetB operations
    Set<char> charMinus = charSetA.minus(charSetB);
    cout << "A - B: ";
    charMinus.display();

    cout << "A intersect B: ";
    Set<char> charIntersect = charSetA.setIntersect(charSetB);
    charIntersect.display();

    cout << "(A-B) union (A intersect B): ";
    charMinus.setUnion(charIntersect).display();
    if(charSetA.equals(charMinus.setUnion(charIntersect))) {
        cout << "All elements in set A are in (A-B) union (A intersect B).";
    } else {
        cout << "All elements in set A are not in (A-B) union (A intersect B).";
    }
    cout << endl << endl;

    /** Case 2 **/
    cout << "/--- CASE 2 ---/\n";
    Set<string> stringSetA;
    stringSetA.insert("Carlos");
    stringSetA.insert("John");
    stringSetA.insert("Alice");
    cout << "stringSetA: ";
    stringSetA.display();

    Set<string> stringSetB;
    stringSetB.insert("John");
    stringSetB.insert("Henry");
    stringSetB.insert("Maria");
    cout << "stringSetB: ";
    stringSetB.display();

    // A minus B
    Set<string> stringMinus = stringSetA.minus(stringSetB);
    cout << "A - B: ";
    stringMinus.display();

    // A intersect B
    Set<string> stringIntersect = stringSetA.setIntersect(stringSetB);
    cout << "A intersect B: ";
    stringIntersect.display();

    cout << "(A-B) union (A intersect B): ";
    stringMinus.setUnion(stringIntersect).display();
    if(stringSetA.equals(stringMinus.setUnion(stringIntersect))) {
        cout << "All elements in set A are in (A-B) union (A intersect B).";
    } else {
        cout << "All elements in set A are not in (A-B) union (A intersect B).";
    }
    cout << endl << endl;

    /** Case 3 **/
    cout << "/--- CASE 3 ---/\n";
    Set<int> intSetA;
    intSetA.insert(5);
    intSetA.insert(1);
    intSetA.insert(3);
    cout << "intSetA: ";
    intSetA.display();

    Set<int> intSetB;
    intSetB.insert(1);
    intSetB.insert(3);
    intSetB.insert(5);
    intSetB.insert(7);
    intSetB.insert(9);
    cout << "intSetB: ";
    intSetB.display();

    // A - B
    cout << "A - B: ";
    Set<int> intMinus = intSetA.minus(intSetB);
    intMinus.display();

    cout << "A intersect B: ";
    Set<int> intIntersect = intSetA.setIntersect(intSetB);
    intIntersect.display();

    cout << "(A-B) union (A intersect B): ";
    intMinus.setUnion(intIntersect).display();
    if(intSetA.equals(intMinus.setUnion(intIntersect))) {
        cout << "All elements in set A are in (A-B) union (A intersect B).";
    } else {
        cout << "All elements in set A are not in (A-B) union (A intersect B).";
    }
    cout << endl << endl;

    /** Case 4 **/
    cout << "/--- CASE 4 ---/\n";
    Set<int> intSetC;
    intSetC.insert(5);
    cout << "intSetC: ";
    intSetC.display();

    Set<int> intSetD;
    cout << "inSetD: ";
    intSetD.display();

    cout << "A - B: ";
    intSetC.minus(intSetD).display();

    cout << "A intersect B: ";
    intSetC.setIntersect(intSetD).display();

    cout << "(A-B) union (A intersect B): ";
    intSetC.minus(intSetD).setUnion(intSetC.setIntersect(intSetD)).display();
    if(intSetC.equals(intSetC.minus(intSetD).setUnion(intSetC.setIntersect(intSetD)))) {
        cout << "All elements in set A are in (A-B) union (A intersect B).";
    } else {
        cout << "All elements in set A are not in (A-B) union (A intersect B).";
    }

    return 0;
}