/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     Raul Aguilar
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>
using namespace std ;

Instructor::Instructor(long id, string name, string address, string phone, string dept, bool perma, double rate, double hours)
    : PersonAtMCC(id, name, address, phone)
{
    setDepartment(dept);
    setIsPermanent(perma);
    setPayRate(rate);
    setHours(hours);
}

// Getters for this class only
string Instructor::getDepartment() {
    return department ;
}

bool Instructor::getIsPermanent() {
    return is_permanent ;
}

double Instructor::getPayRate() {
    return pay_rate ;
}

double Instructor::getHours() {
    return hours;
}

// Setters for this class only
void Instructor::setDepartment(string new_department) {
    department = new_department ;
}

void Instructor::setIsPermanent(bool new_is_permanent) {
    is_permanent = new_is_permanent ;
}

void Instructor::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Instructor::setHours(double new_hours) {
    hours = new_hours;
}

void Instructor::showInfo() {
    PersonAtMCC::showInfo();
    cout << "\tDepartment: " << getDepartment();
    cout << "\tPermanent?: ";
    if (getIsPermanent()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << "\tPay Rate: " << getPayRate();
    cout << "\tHours: " << getHours() << endl;
}
