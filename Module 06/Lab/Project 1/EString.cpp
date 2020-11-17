/* EStrings.cpp - Enhance the String class using overloaded functions (original)
 * Author:    Chris Merrill
 * Module:    6
 * Project:   Lab #1
 * Problem statement:  Enhance the String class from Module 5, Lab 2 using
 *    overloaded functions to assignment, addition, extraction, and upper-case operators
 *
 * Discussion:
 *    - Starting point for Lab 6 (from Lab 5)
 */

#include<iostream>
#include<cstring>
using namespace std;

class EString {

private:
    char *str ;                                // pointer to an array of chars
    int size ;                                 // size of the array

public:
    EString(const char *s = "") ;              // constructor
    ~EString() ;                               // destructor
    EString(const EString &) ;                 // copy constructor
    EString& operator=(const EString&);
    friend ostream& operator<<(ostream&, const EString&);
    EString operator++();
    EString operator++(int);
    char & operator[](int);
    friend EString operator+(const EString &, const EString &);
    int length();
};

// Constructor
EString::EString(const char *original) {
    size = strlen(original) ;
    str = new char[size + 1] ;
    strcpy(str, original) ;
}

// Destructor
EString::~EString() {
    delete [] str ;
}

// Copy constructor which creates a new String
EString::EString(const EString &original) {
    size = original.size ;
    str = new char[size + 1] ;
    strcpy(str, original.str) ;
}

EString& EString::operator=(const EString& original)
{
    delete[] str;
    size = original.size;
    str = new char[size + 1];
    strcpy(str, original.str);
    return *this;
}

ostream& operator<<(ostream& out, const EString& output_EString)
{
    out << output_EString.str;
    return out;
}

EString EString::operator++()
{
    for(int i = 0; i < size; i++)
    {
        if(islower(*(str+i)))
        {
            *(str+i) = toupper(*(str+i));
        }
    }
    return *this;
}

EString EString::operator++(int)
{
    EString temp = *this;
    for(int i = 0; i < size; i++)
    {
        *(str+i) = toupper(*(str+i));
    }
    return temp;
}

char& EString::operator[](int index)
{
    if(index < 0 || index > size)
    {
        cout << "Out of bound index. Program exiting." << endl;
        exit(0);
    }
    return *(str+index);
}

EString operator+(const EString &first, const EString &second) {
    int length = (first.size + second.size) + 1;
    char *str = new char[length];
    strcpy(str, first.str);
    strcat(str, second.str);
    return EString(str);
}

int EString::length() { return size; }

int main() {
    // Testing assignment and stream insertion operators
    EString e1 = "Hello MiraCosta!", e2;
    e2 = e1;
    cout << "First string: " << e1 << endl
         << "Second string: " << e2 << endl << endl;

    // Testing prefix++
    EString e3 = "She's holding me tight.";
    cout << "Original: " << e3
    << "\nUsing prefix: " << ++e3
    << "\nAfter prefix: " << e3 << endl;

    // Testing postfix++
    EString e4 = "You know I'll always stay by your side.";
    cout << "\nOriginal: " << e4
    << "\nUsing postfix: " << e4++
    << "\nAfter postfix: " << e4 << endl;

    // Testing operator+
    EString e5 = e3 + e4;
    cout << '\n' << e5 << endl;

    // Testing operator[] overload
    for(int i = 0; i < e3.length(); i++) {
        cout << e3[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < e3.length(); i++) {
        cout << ++e3[i] << " ";
    }
    cout << endl;

    return 0 ;
}
