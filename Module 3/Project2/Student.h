/*
 * author	Raul Aguilar
 * date		September 9, 2020
 * 
 * CS 151 3228 Homework 3 Project 2
 * Student record class to hold the name of the student and their test
 * score.
 */
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int score;
public:
	Student();
	Student(string, int);
	~Student();
	string getName();
	int getScore();
	void setName(string);
	void setScore(int);
};
#endif // !STUDENT_H
