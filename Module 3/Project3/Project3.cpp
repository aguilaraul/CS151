/*
* Project3.cpp
* 
* author	Raul Aguilar
* date		September 13, 2020
* 
* CS 151 3228 Homework 3 Project 3
* In statistics, the mode of a set of values is the value that occurs
* most often. Write a program that determines how many pieces of pie
* most people eat in a year.
* 
* Algorithm:
* 1. Dynamically allocate array of respones to the correct size
* 2. Input 30 respones of the number of pie slices eaten in a year
* 3. Sort array into ascending order
* 4. Find mode by counting the number of slices with the most responses
*	Count the number of occurances of the current number.
*	If a new number is scanned, and if current count is greater than the
*	total, then a new mode is found.
*	Set total to current count and set mode to current number
*	Set the current number to the new number scanned and reset count
*/
#include <iostream>

using namespace std;

int mode(int[], int);
void printRespones(int[], int);
void bubbleSort(int[], int);
void swap(int&, int&);

const int SIZE = 30;

int main()
{
	// Dynamically allocate array of respones
	int* responses = new int[SIZE];

	// Input number pie slices eaten by each person per year
	cout << "Enter number of pie slices each person eats in a year:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> *(responses + i);
	}

	// Sort array into ascending order
	bubbleSort(responses, SIZE);

	// Print sorted responses
	printRespones(responses, SIZE);

	// Find mode of respones
	cout << "The number of slices with the most responses:" << endl;
	cout << mode(responses, SIZE) << endl;

	delete[] responses;
	responses = nullptr;
	return 0;
}

int mode(int array[], int size)
{
	int mode = array[0];
	int total = 1;
	int current = array[0];
	int count = 1;

	for (int i = 1; i < size; i++)
	{
		// Count the number of occurances of the current number
		// If current number is equal to number in array, then increase tally
		if (current == array[i])
		{
			count++;
		}
		// Current number is differnt than number in array
		// Tally streak broken
		else
		{
			// If the current count is greater than the total, then new mode is
			// found. Set total to current count and set mode to current number
			if (count > total)
			{
				total = count;
				mode = current;
			}
			current = array[i]; // set current number to new number
			count = 1; // reset count
		}
	}
	return mode;
}

void printRespones(int array[], int size)
{
	cout << "Number of slices:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(array + i) << endl;
	}
}

void bubbleSort(int array[], int size)
{
	bool madeSwap = true;
	for (int maxElement = size - 1; maxElement > 0 && madeSwap; maxElement--)
	{
		madeSwap = false;
		for (int i = 0; i < maxElement; i++)
		{
			if (*(array + i) > * (array + (i + 1)))
			{
				swap(*(array + i), *(array + (i + 1)));
				madeSwap = true;
			}
		}
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}