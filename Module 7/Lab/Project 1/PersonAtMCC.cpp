/* PersonAtMCC.cpp - Function definitions for parent class
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:  Function definitions for parent class
 */

#include "PersonAtMCC.h"
#include <iostream>
using namespace std ;

// Constructors
PersonAtMCC::PersonAtMCC() {
	setId(0);
	setName("No Name");
	setAddress("No Address");
	setPhone("No Phone");
}

PersonAtMCC::PersonAtMCC(long id, string name) {
	setId(id);
	setName(name);
	setAddress("No Address");
	setPhone("No Phone");
}

PersonAtMCC::PersonAtMCC(long id, string name, string address, string phone) {
	setId(id);
	setName(name);
	setAddress(address);
	setPhone(phone);
}

// getters and setters
long PersonAtMCC::getId() {
    return id ;
}

string PersonAtMCC::getName() {
    return name ;
}

string PersonAtMCC::getAddress() {
    return address ;
}

string PersonAtMCC::getPhone() {
    return phone ;
}

// Setters
void PersonAtMCC::setId(long new_id) {
    id = new_id ;
}

void PersonAtMCC::setName(string new_name) {
    name = new_name ;
}

void PersonAtMCC::setAddress(string new_address) {
    address = new_address ;
}

void PersonAtMCC::setPhone(string new_phone) {
    phone = new_phone ;
}

// Output
void PersonAtMCC::showInfo() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}
