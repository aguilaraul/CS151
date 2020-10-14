/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     Raul Aguilar
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTOR, USE MEMBER INITIALIZATION ****/
Instructor::Instructor(long id, string name, string address, string phone,
						bool permanent, double rate, double hours)
			: PersonAtMCC(id, name, address, phone)
{
	setIsPermanent(permanent);
	setPayRate(rate);
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

void Instructor::showInfo() {
    cout << "ID: " << getId() << endl ;

    /**** COMPLETE THE OUTPUT ****/
}
