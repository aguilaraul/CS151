/**
 * Raul Aguilar
 * November 9, 2020
 * CS 151 3228 Midterm Problem 4
 */

#include <iostream>
using namespace std ;

class Person {
private:
    string profession ;
    int age ;

public:
    // Constructor
    Person(const string& prof, int a) {
        profession = prof;
        age = a;
    }
    // Setters
    void setProfession(const string& prof) {
        profession = prof;
    }
    void setAge(int a) {
        age = a;
    }
    // Getters;
    string getProfession() const {
        return profession;
    }
    int getAge() const {
        return age;
    }
} ;

class Teacher : public Person {                 // make a child of Person
public:
    // Constructor
    Teacher(int age)
    : Person("Teacher", age){}
    Teacher(const string& profession, int age)
    : Person(profession, age) {}
    // method
    void teach() {
        cout << "The " << getProfession() << " is teaching." << endl;
    }
} ;

class MathTeacher : public Teacher {            // make a child of Teacher
public:
    // Add a constructor which takes an age, calls Teacher constructor with "Math Teacher" as profession
    MathTeacher(int age)
    :   Teacher("Math Teacher", age){}
} ;

int main() {

    // Create a Person object, a Teacher object, and a MathTeacher object
    Person person("Worker", 27) ;
    Teacher teacher(42) ;
    MathTeacher mathTeacher(39) ;

    cout << "The person's profession is: " << person.getProfession()
         << " and is " << person.getAge() << " years old" << endl ;
    cout << "The teacher's profession is: " << teacher.getProfession()
         << " and is " << teacher.getAge() << " years old" << endl ;
    cout << "The mathTeacher's profession is: " << mathTeacher.getProfession()
         << " and is " << mathTeacher.getAge() << " years old" << endl << endl ;

    teacher.teach() ;
    mathTeacher.teach() ;

    return 0;
}
