/*
 * author   Raul Aguilar
 * date     September 15, 2020
 * 
 * CS 151 3228 Homework 3 Project 1
 * Write a program that dynamically allocates an array large enough to
 * hold a user-defined number of test scores.
 * 
 * Algorithm:
 * 1. Ask user for number of test scores to input
 * 2. Dynamically allocate the correct array
 * 3. Input test scores through the terminal rejecting negative
 * integers
 * 4. Sort the array of test scores in acsending order
 * 5. Calculate the average test score
 * 6. Display the sorted test scores and average with the appropriate
 * headers
 */
#include <iostream>
#include <iomanip>

using namespace std;

void inputScores(int[], int);
void bubbleSort(int[], int);
void swap(int &, int &);
void printScores(int[], int);
float calculateAverage(int[], int);

int main()
{
    int size;
    cout << "How many test scores would you like to enter?" << endl;
    cin >> size;
    int *scores = new int[size];

    // Input test scores
    inputScores(scores, size);
    // Sort array into ascending order
    bubbleSort(scores, size);

    // Display scores and average
    printScores(scores, size);
    cout << endl << "Average:" << endl;
    cout << right << setw(6) << calculateAverage(scores, size) << endl;

    delete [] scores;
    return 0;
}

void inputScores(int array[], int size)
{
    bool validInput;
    int score;
    cout << endl << "Enter test scores:" << endl;
    for(int i = 0; i < size; i++)
    {
        validInput = false;
        score = 0;
        while(!validInput)
        {
            cin >> score;
            if(score >= 0)
            {
                *(array + i) = score;
                validInput = true;
            } else
            {
                cout << "Invalid input. Enter score greater or equal to 0." << endl;
            }
        }
    }
}

void bubbleSort(int array[], int size)
{
    bool madeASwap = true;
    for(int maxElement = size - 1; maxElement > 0 && madeASwap; maxElement--)
    {
        madeASwap = false;
        for(int i = 0; i < maxElement; i++)
        {
            if(array[i] > array[i+1])
            {
                swap(array[i], array[i+1]);
                madeASwap = true;
            }
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printScores(int array[], int size)
{
    cout << endl << "Scores:" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << right << setw(6) << *(array + i) << endl;
    }
}

float calculateAverage(int array[], int size)
{
    float sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }
    return sum/size;
}