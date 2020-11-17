/*
 * lab5_part2.cpp
 *
 * author   Raul Aguilar
 * date     October 7, 2020
 *
 * CS 151 3228 Module 5 Lab 5 Part 2
 * Develop a copy constructor which fixes a issues with shallow copies.
 *
 * Algorithm:
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char *string;
    int size;
public:
    String(const char *s = "");
    String(const String &);
    ~String();
    void print();
    void change(const char *);
};

String::String(const char *original)
{
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

// Copy constructor
String::String(const String &original)
{
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

String::~String()
{
    delete [] string;
}

void String::print()
{
    cout << string << endl;
}

void String::change(const char *original)
{
    delete [] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

int main()
{
    // Create String using a constructor and assignment statement
    cout << "Create two strings: one using a constructor";
    cout << " another an assignment statement." << endl;
    String str1("MiraCosta College");
    String str2 = str1;

    // Print both Strings to the console
    str1.print();
    str2.print();

    // Change the second String
    cout << endl << "After changing string 2 using change()" << endl;
    str2.change("Cal State San Marcos");
    str1.print();
    str2.print();

    // Change the first String
    cout << endl << "After changing string 1 using change()" << endl;
    str1.change("UCSD");
    str1.print();
    str2.print();

    return 0;
}
