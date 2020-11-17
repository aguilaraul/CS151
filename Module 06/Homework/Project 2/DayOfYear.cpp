/*
 * DayOfYear.cpp
 * Author:	Raul Aguilar
 * Date:	October 29, 2020
 * CS 151 3228 Module 6 Homework 6 Project 1
 * Day of year class
 */
#include <iostream>
#include "DayOfYear.h"

using namespace std;

DayOfYear::DayOfYear(int num)
{
	// Algorithm:
	// 1. Cycle through each month to determine which month the day number
	// occurs in.
	//	- If the day number is less than 31 then the month is January and
	// the corresponding day number is correct
	//	- If the day number is greater than the current month's last day
	//	number and less than or equal to next month's last day number, then
	//	the day number occurs next month
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

DayOfYear::DayOfYear(string month, int day)
{
	// Algoritm:
	// Find the user month in the array of months
	// If a match is not found, state so to the terminal and terminate the
	// program
	// If a match is found, determine if the day is within the days of
	// that month. If not, state so and terminate the program.
	// If the month and day are valid, get the total number of days at the
	// end of the previous month and add on the user's day to convert
	// to the number day of the year.
	int index = distance(MONTH, find(MONTH, MONTH + 12, month));
	if (index != 12)
	{
		if (day > 0 && day <= DAYSINMONTH[index])
		{
			if (index == 0)
			{
				dayNumber = day;
			} else
			{
				dayNumber = DAYSINYEAR[index - 1] + day;
			}
			
			cout << dayNumber << endl;
		} else
		{
			cout << day << " is not within range of " << month;
			cout << "\nRerun program and enter valid date." << endl;
			exit(0);
		}
	} else
	{
		cout << month << " is not valid. Rerun program and enter valid month." << endl;
		exit(0);
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

DayOfYear DayOfYear::operator++()
{
	// If it is already December 31, day 365, then loop back to start
	// of the year, January 1, day 1
	// Otherwise, increment the day number by 1
	if (dayNumber == 365)
	{
		dayNumber = 1;
	} else
	{
		dayNumber++;
	}
	return *this;
}

DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp = *this;
	if (dayNumber == 365)
	{
		dayNumber = 1;
	} else
	{
		++dayNumber;
	}
	return temp;
}

DayOfYear DayOfYear::operator--()
{
	// If it is already January 1, day 1, then loop to end
	// of the year, December 31, day 365
	// Otherwise, decrement the day number by 1
	if (dayNumber == 1)
	{
		dayNumber = 365;
	} else
	{
		dayNumber--;
	}
	return *this;
}

DayOfYear DayOfYear::operator--(int)
{
	DayOfYear temp = *this;
	if (dayNumber == 1)
	{
		dayNumber = 365;
	} else
	{
		--dayNumber;
	}
	return temp;
}

const int DayOfYear::DAYSINMONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int DayOfYear::DAYSINYEAR[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const string DayOfYear::MONTH[] = { "January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November",
									"December" };
