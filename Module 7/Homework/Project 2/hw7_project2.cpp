/**
 * hw7_project2.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 Module 7 Homework 7 Project 2
 * Write a class named EncryptableString that is derived from the STL
 * string class. The EncryptableString class adds a member function
 * which encrypts the string contained in the object by replacing each
 * letter with its successor in the ASCII ordering.
 *
 * Algorithm:
 * 1. Take input string from user
 * 2. Loop through the characters in the string
 * 3. Check if current character is alphanumeric
 *  If not, then do nothing
 *  If it is, then check if character is 'z', 'Z', or '9'
 *      If so, make the appropriate change to the successor
 *      If not, then increment character by 1
 * 4. Print out encrypted string
 */
#include <iostream>
#include <algorithm>

using namespace std;

class EncryptableString : public string {
public:
    EncryptableString(const string&);
    void encrypt();
};

EncryptableString::EncryptableString(const string& original)
    : string(original)
{
    encrypt();
}


void EncryptableString::encrypt() {
    for(int i = 0; i < (*this).length(); i++) {
        if(isalnum((*this)[i])) {
            if((*this)[i] == 'z') {
                (*this)[i] = 'a';
            } else if((*this)[i] == 'Z') {
                (*this)[i] = 'A';
            } else if((*this)[i] == '9') {
                (*this)[i] = '0';
            } else {
                (*this)[i]++;
            }
        }
    }
    cout << (*this) << endl;
}

int main() {
    string input;
    cout << "Enter a phrase to encrypt:" << endl;
    getline(cin, input);

    EncryptableString string1(input);

    return 0;
}
