/*
 * DayOfYear.h
 * Author:	Raul Aguilar
 * Date:	October 29, 2020
 * CS 151 3228 Module 6 Homework 6 Project 1
 * Day of year class header
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>
using namespace std;

class DayOfYear
{
private:
	int dayNumber;
public:
	DayOfYear(int);
	DayOfYear(string, int);
	int getDayNumber();
	friend istream& operator>>(istream& in, DayOfYear& d);
	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);
	static const int DAYSINMONTH[];
	static const int DAYSINYEAR[];
	static const string MONTH[];
};


#endif // !DAYOFYEAR_H
