/* Student.cpp - Function definitions for Student class, child of PersonAtMCC
 * Author:     Raul Aguilar
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Student.h"
#include <iostream>
using namespace std ;

Student::Student(long id, string name, string address, string phone, string major, int credits, bool applied, bool vet)
    : PersonAtMCC(id, name, address, phone)
{
    setMajor(major);
    setCreditsReceived(credits);
    setAppliedTo4Year(applied);
    setIsVeteran(vet);
}

// Getters for this class only
string Student::getMajor() {
    return major ;
}

int Student::getCreditsReceived() {
    return credits_received ;
}

bool Student::getAppliedTo4Year() {
    return applied_to_4_year ;
}

bool Student::getIsVeteran() {
    return is_veteran ;
}

// Setters
void Student::setMajor(string new_major) {
    major = new_major ;
}

void Student::setCreditsReceived(int new_credits_received) {
    credits_received = new_credits_received ;
}

void Student::setAppliedTo4Year(bool new_has_applied) {
    applied_to_4_year = new_has_applied ;
}

void Student::setIsVeteran(bool new_is_veteran) {
    is_veteran = new_is_veteran ;
}

void Student::showInfo() {
    PersonAtMCC::showInfo();
    cout << "\tMajor: " << getMajor();
    cout << "\tCredits: " << getCreditsReceived();
    cout << "\t4-year? ";
    if (getAppliedTo4Year()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << "\tVeteran? ";
    if (getIsVeteran()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
}


