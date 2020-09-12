/*
 * author   Raul Aguilar
 * date     September 9, 2020
 * 
 * CS 151 3228 Homework 3 Project 2
 * Write a program that dynamically allocates an array large enough to
 * hold a user-defined number of test scores. Allow the user to enter
 * name-score pairs.
 * 
 * Algorithm:
 * 
 */
#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

void inputScores(Student[], int);
void printScores(Student[], int);

int main()
{
    // Dynamically allocate array
    int size;
    cout << "How many test scores would you like to enter?" << endl;
    cin >> size;
    Student* scores = new Student[size];

    // Input students' name and test score
    inputScores(scores, size);

    // Print scores
    printScores(scores, size);
}

void inputScores(Student array[], int size)
{
    bool validInput;
    string name;
    int score;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter student's name:" << endl;
        cin >> name;
        cout << "Enter test score:" << endl;
        validInput = false;
        score = 0;
        while (!validInput)
        {
            cin >> score;
            if (score >= 0)
            {
                validInput = true;
            } else
            {
                cout << "Invalid input. Enter score greater or equal to 0." << endl;
            }
        }

        Student s = Student(name, score);
        *(array + i) = s;
    }
}

void printScores(Student array[], int size)
{
    cout << endl << "Name";
    cout << " Score" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << right << setw(6) << array[i].getName() << endl;
    }
}