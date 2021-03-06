/**
 * Person.h
 *
 * Author:  Raul Aguilar
 * Date:    December 16, 2020
 * Header file for Person class
 */

#ifndef FM20SCOUT_PERSON_H
#define FM20SCOUT_PERSON_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Person {
protected:
    string nation;
    string name;
    int age;
public:
    Person();
    Person(const string&, const string&, int);
    virtual ~Person();
    void setNation(const string&);
    void setName(const string&);
    void setAge(int);
    string getNation() const;
    string getName() const;
    int getAge() const;
    virtual string to_string();
};

#endif //FM20SCOUT_PERSON_H
