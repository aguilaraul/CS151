/*
 * hw11_project3.cpp
 * Author:  Raul Aguilar
 * Date:    November 12, 2020
 *
 * CS 151 3228 Module 11 Homework 11 Project 3
 * Write a recursive function with the heading:
 *  `bool isPalindrome(string str, int lower, int upper)`
 * that returns true if and only if the part of the string str in
 * positions lower through upper (inclusive at both ends) is a
 * palindrome.
 *
 * Algorithm:
 * 1. Base case: check if the string is 1 character long.
 *  If so, position at middle of the string and is a palindrome
 * 2. Check if first and last index in string is a alphanumeric
 *  If not, check if still palindrome without that character
 * 3. If first and last character match, check every letter in between
 * 4. If first and last character do not match, then string is not a
 * palindrome
 * */
#include <iostream>
using namespace std;

bool isPalindromeHelper(string, int, int);
bool isPalindrome(string);

int main() {
    string testPalindrome;
    int lower = 0, upper = testPalindrome.length();

    // Get phrase
    cout << "Enter a phrase to test if palindrome:\n";
    getline(cin, testPalindrome);

    // Test palindrome
    while(!testPalindrome.empty()) {
        if(isPalindrome(testPalindrome)) {
            cout << testPalindrome << " is a palindrome." << endl;
        } else {
            cout << testPalindrome << " is not a palindrome." << endl;
        }
        cout << "\nEnter a phrase to test if palindrome:\n";
        getline(cin, testPalindrome);
    }

    cout << "Exiting..." << endl;
    return 0;
}

bool isPalindrome(string str) {
    return isPalindromeHelper(str, 0, str.length());
}

bool isPalindromeHelper(string str, int lower, int upper) {
    char i;
    char j;

    if(str.substr(lower,upper).length() == 1) {
        return true;
    }

    // Check the first character
    if(isalnum(str[lower])) {
        i = tolower(str[lower]);
    } else {
        return isPalindromeHelper(str, lower+1, upper);
    }

    // Check the last character
    if(isalnum(str[upper])) {
        j = tolower(str[upper]);
    } else {
        return isPalindromeHelper(str, lower, upper-1);
    }

    // Check both chars against each other
    if(i == j) {
        return isPalindromeHelper(str, lower+1, upper-1);
    } else {
        return false;
    }
}


