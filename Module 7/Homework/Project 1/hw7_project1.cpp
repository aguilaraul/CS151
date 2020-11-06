/*
 * hw7_project1.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 3228 Module 7 Homework 7 Project 1
 * Write a class PString that is derived from the STL string class. The
 * PString class should add a member function which determines whether
 * the string is a palindrome.
 *
 * Algorithm:
 * 1. Base case: check if the string is 1 character long.
 *  If so, position at middle of the string and is a palindrome
 * 2. Check if first and last index in string is a alphanumeric
 *  If not, check if still palindrome without that character
 * 3. If first and last character match, check every letter in between
 * 4. If first and last character do not match, then string is not a
 * palindrome
 *
 * */
#include <iostream>
using namespace std;

class PString : public string {
private:
    string input;
public:
    PString(string);
    bool isPalindrome(string);
};

PString::PString(string in) {
    input = in;

    if(isPalindrome(input)) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }
}

bool PString::isPalindrome(string str) {
    char i;
    char j;

    if(str.length() == 1) {
        return true;
    }

    // Check the first character
    if(isalnum(str[0])) {
        i = tolower(str[0]);
    } else {
        return isPalindrome(str.substr(1));
    }

    // Check the last character
    if(isalnum(str[str.length()-1])) {
        j = tolower(str[str.length()-1]);
    } else {
        return isPalindrome(str.substr(0, str.length()-1));
    }

    // Check both chars against each other
    if(i == j) {
        return isPalindrome(str.substr(1, str.length()-2));
    } else {
        return false;
    }
}

int main() {
    string testStr;
    cout << "Check if a phrase is a palindrome:" << endl;
    getline(cin, testStr);

    PString string1(testStr);

    return 0;
}
