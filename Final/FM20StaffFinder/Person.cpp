//
// Created by raula on 11/7/2020.
//

#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    setNation("");
    setName("");
    setAge(0);
}

Person::Person(const string& nation, const string& name, int age) {
    setNation(nation);
    setName(name);
    setAge(age);
}

Person::~Person() = default;

void Person::setNation(const string& n) {
    this->nation = n;
}

void Person::setName(const string& n) {
    this->name = n;
}

void Person::setAge(int a) {
    this->age = a;
}

string Person::getNation() {
    return this->nation;
}

string Person::getName() {
    return this->name;
}

int Person::getAge() const {
    return this->age;
}

string Person::to_string() {
    return name + " is " + std::to_string(age) + " years old" +
        " and is from " + nation + '.';
}
