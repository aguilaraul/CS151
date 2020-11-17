/* Staff.cpp - Function definition file for Staff, child of PersonAtMCC
 * Author:     Raul Aguilar
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Staff.h"
#include <iostream>
using namespace std ;

Staff::Staff(long id, string name, string address, string phone, string ext, string hireDate, double rate)
    : PersonAtMCC(id, name, address, phone)
{
    setExtension(ext);
    setHireDate(hireDate);
    setPayRate(rate);
}

// Getters for this class only
string Staff::getExtension() {
    return extension ;
}

string Staff::getHireDate() {
    return hire_date ;
}

double Staff::getPayRate() {
    return pay_rate ;
}

// Setters for this class only
void Staff::setExtension(string new_extension) {
    extension = new_extension ;
}

void Staff::setHireDate(string new_hire_date) {
    hire_date = new_hire_date ;
}

void Staff::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Staff::showInfo() {
    PersonAtMCC::showInfo();
    cout << "\tExtension: " << getExtension();
    cout << "\tHire Date: " << getHireDate();
    cout << "\tPay Rate: " << getPayRate() << endl;
}

