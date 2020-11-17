/*
 * Student.cpp
 * 
 * author	Raul Aguilar
 * date		September 9, 2020
 *
 * CS 151 3228 Homework 3 Project 2
 * Student record class to hold the name of the student and their test
 * score.
 */
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
	name = "no name";
	score = -1;
}

Student::Student(string n, int s)
{
	name = n;
	score = s;
}

Student::~Student() {}

string Student::getName()
{
	return name;
}

int Student::getScore()
{
	return score;
}

void Student::setName(string n)
{
	name = n;
}

void Student::setScore(int s)
{
	score = s;
}