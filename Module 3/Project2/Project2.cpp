/* 
 * Project2.cpp
 * 
 * author   Raul Aguilar
 * date     September 13, 2020
 * 
 * CS 151 3228 Homework 3 Project 2
 * Write a program that dynamically allocates an array large enough to
 * hold a user-defined number of test scores. Allow the user to enter
 * name-score pairs.
 * 
 * Algorithm:
 * 1. Ask user input how many scores they would like to enter
 * 2. Dynamically allocate an array of Students to the correct size
 * 3. Input student names and scores
 *  Validate score by checking if it is less than zero. If it is, then
 *  state so and ask to re-enter score. Otherwise, score is valid.
 * 4. Sort array by student score into ascending order
 * 5. Print the sorted array of student names and their score with
 * the appropriate headings.
 *  Calculate the average score and display it
 */
#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

void inputScores(Student[], int);
void bubbleSort(Student[], int);
void swap(Student&, Student&);
void printScores(Student[], int);
float calculateAverage(Student[], int);

int main()
{
    // Dynamically allocate array of Student objects
    int size;
    cout << "How many test scores would you like to enter?" << endl;
    cin >> size;
    Student* scores = new Student[size];

    // Input students' name and test score
    inputScores(scores, size);
    // Sort student scores into ascending order
    bubbleSort(scores, size);
    // Print scores and average
    printScores(scores, size);

    delete[] scores;
    scores = nullptr;
    return 0;
}

void inputScores(Student array[], int size)
{
    bool validInput;
    string name;
    int score;
    for (int i = 0; i < size; i++)
    {
        cout << endl << i+1 << ") Enter student's name:" << endl;
        cin >> name;
        cout << right << setw(20) << "Enter test score:" << left << endl;
        validInput = false;
        score = 0;
        while (!validInput)
        {
            cin >> score;
            if (score < 0)
            {
                cout << "Invalid input. Enter score greater or equal to 0." << endl;
            } else
            {
                validInput = true;
            }
        }

        Student s = Student(name, score);
        *(array + i) = s;
    }
}

void bubbleSort(Student array[], int size)
{
    bool madeASwap = true;
    for (int maxElement = size - 1; maxElement > 0 && madeASwap; maxElement--)
    {
        madeASwap = false;
        for (int i = 0; i < maxElement; i++)
        {
            if (array[i].getScore() > array[i + 1].getScore())
            {
                swap(*(array+i), *(array+(i+1)));
                madeASwap = true;
            }
        }
    }
}

void swap(Student& a, Student& b)
{
    Student temp = a;
    a = b;
    b = temp;
}

void printScores(Student array[], int size)
{
    cout << endl << setw(12) << "Name";
    cout << " Score" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(12) << array[i].getName();
        cout << right << setw(6) << array[i].getScore() << endl;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Average" << setw(11) << fixed << setprecision(2) << calculateAverage(array,size);
}

float calculateAverage(Student array[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i].getScore();
    }

    return sum / size;
}