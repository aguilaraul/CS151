/*
 * DayOfYear.cpp
 * Author:	Raul Aguilar
 * Date:	October 28, 2020
 * CS 151 3228 Module 6 Homework 6 Project 1
 * Day of year class
 */
#include <iostream>
#include "DayOfYear.h"

using namespace std;

DayOfYear::DayOfYear(int num)
{
	// Algorithm:
	// 1. Cycle through each month to determine when the day number occurs
	// If the day number is less than 31 then the month is January and the
	// corresponding day number is correct
	// If the day number is greater than the previous month's last day
	// number and less than or equal to next month's last day number, then
	// the day number occurs next month
	// 2. To get the day, subtract the previous month's last day number
	// from the user's day number
	int index = 0;
	dayNumber = num;
	for (int i = 0; i < 12; i++) {
		if (dayNumber < DAYSINYEAR[0]) {
			index = 0;
		} else if (dayNumber > DAYSINYEAR[i] && dayNumber <= DAYSINYEAR[i + 1]) {
			index = i + 1;
		}
	}

	// Print out the month and day
	cout << MONTH[index] << " ";
	if (index == 0)
	{
		cout << dayNumber << endl;
	} else
	{
		cout << dayNumber - DAYSINYEAR[index - 1] << endl;
	}
}

int DayOfYear::getDayNumber()
{
	return dayNumber;
}

//istream& operator>>(istream& in, DayOfYear& d)
//{
//	in >> d.dayNumber;
//	return in;
//}

const int DayOfYear::DAYSINMONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int DayOfYear::DAYSINYEAR[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const string DayOfYear::MONTH[] = { "January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November",
									"December" };
