//
// Created by raula on 11/7/2020.
//

#ifndef FM20SCOUT_PERSON_H
#define FM20SCOUT_PERSON_H
#include <iostream>
using namespace std;

class Person {
protected:
    string nation;
    string name;
    int age;
public:
    Person();
    Person(const string&, const string&, int);
    ~Person();
    void setNation(const string&);
    void setName(const string&);
    void setAge(int);
    string getNation();
    string getName();
    int getAge() const;
    virtual string to_string();
};

#endif //FM20SCOUT_PERSON_H
