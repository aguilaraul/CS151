/*
 * hw6_project1.cpp
 * 
 * Author:	Raul Aguilar
 * Date:	October 28, 2020
 * 
 * CS 151 3228 Module 6 Homework 6 Project 1
 * Assuming that a year has 365 days, write a class named DayOfYear
 * that takes an integer representing a day of the year and translates
 * it to a string for output consisting of the month followed by day of
 * the month.
 * 
 * Algorithm:
 * 1. Get day number from user
 * 2. Determine which month the day number is in. If the day number is
 * greater than last month's last day and less than or equal to the
 * last day of the current month, then the day number falls on the
 * current month.
 * 3. Determine the day in the month. Subtract the previous month's
 * last day number from the user's day number
 * 4. Print month and day
 */
#include "DayOfYear.h"
#include <iostream>

using namespace std;

int inputDay();

int main() {
    DayOfYear d(inputDay());

	return 0;
}

int inputDay()
{
    int num;
    bool validInput = false;
    cout << "Enter a day number between 1 and 365.\n";
    cin >> num;

    while (!validInput) {
        if (num < 1 || num > 365) {
            cout << "Invalid input. Re-enter number between 1 and 365.\n";
            cin >> num;
        } else {
            validInput = true;
        }
    }
    return num;
}
