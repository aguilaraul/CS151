/*
 * hw6_project2.cpp
 *
 * Author:	Raul Aguilar
 * Date:	October 29, 2020
 *
 * CS 151 3228 Module 6 Homework 6 Project 1
 * Assuming that a year has 365 days, write a class named DayOfYear
 * that takes an integer representing a day of the year and translates
 * it to a string for output consisting of the month followed by day of
 * the month.
 *
 * Algorithm:
 * 1. Take month and day from user
 * 2. Find the month provided within the month array.
 * If no match is found, state so to terminal and terminate program.
 * If a match is found, determine if the day is within the number of
 * days of that month.
 * If the day provided is outside the range of days, state so and
 * terminate the program.
 * If the month and day are valid, get the total number of days at the
 * end of the previous month and add on the day from the user. If it's
 * January, the day provided is already correct.
 */
#include "DayOfYear.h"
#include <iostream>
#include <string>

using namespace std;

int inputDay();
void inputMonthDay(string&, int&);

int main() {
    string month = "";
    int day = -1;
    DayOfYear* date;

    inputMonthDay(month, day);
    date = new DayOfYear(month, day);
    
    
    // Testing prefix--
    date = new DayOfYear(inputDay());
    cout << "Original Value:\n";
    DayOfYear(date->getDayNumber());
    
    cout << "\nUsing prefix--:\n";
    --*date;
    DayOfYear(date->getDayNumber());

    cout << "\nAfter prefix--:\n";
    DayOfYear(date->getDayNumber());

    // Testing prefix++
    cout << endl;
    date = new DayOfYear(inputDay());
    cout << "Original Value:\n";
    DayOfYear(date->getDayNumber());

    cout << "\nUsing prefix++:\n";
    ++* date;
    DayOfYear(date->getDayNumber());

    cout << "\nAfter prefix++:\n";
    DayOfYear(date->getDayNumber());

    // Testing postfix--
    cout << endl;
    inputMonthDay(month, day);
    date = new DayOfYear(month, day);
    cout << "Original Value:\n";
    DayOfYear(date->getDayNumber());

    cout << "\nUsing postfix--:\n";
    (*date)--;
    DayOfYear(date->getDayNumber());

    cout << "\nAfter postfix--:\n";
    DayOfYear(date->getDayNumber());

    // Testing postfix++
    inputMonthDay(month, day);
    date = new DayOfYear(month, day);
    cout << "Original Value:\n";
    DayOfYear(date->getDayNumber());

    cout << "\nUsing postfix++:\n";
    (*date)++;
    DayOfYear(date->getDayNumber());

    cout << "\nAfter postfix++:\n";
    DayOfYear(date->getDayNumber());
    
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
    cout << endl;
    return num;
}

void inputMonthDay(string &m, int &d)
{
    string date = "";
    cout << "Please enter a month and day to retreive the day number:\n";
    cout << "Month: ";
    cin >> m;
    cout << "Day: ";
    cin >> d;
    cout << endl;
}
