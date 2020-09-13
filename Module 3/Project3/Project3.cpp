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
*	
*/
#include <iostream>

using namespace std;

int mode(int[], int);
void printRespones(int[], int);
void bubbleSort(int[], int);
void swap(int&, int&);

const int SIZE = 5;

int main()
{
	// Dynamically allocate array of respones
	int* respones = new int[SIZE];

	// Input number pie slices eaten by each person per year
	cout << "Enter number of pie slices each person eats in a year:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> *(respones + i);
	}

	// Sort array into ascending order
	bubbleSort(respones, SIZE);

	// Find mode of respones
	cout << "The number of slices with the most responses:" << endl;
	cout << mode(respones, SIZE) << endl;

	// Print sorted responses
	printRespones(respones, SIZE);

	delete[] respones;
	respones = nullptr;
	return 0;
}

int mode(int array[], int size)
{
	int mode;
	int total = 0;
	int current = array[0];
	int count = 1;

	for (int i = 1; i < size; i++)
	{
		if (current == array[i])
		{
			count++;
		} else
		{
			if (count > total)
			{
				total = count;
				mode = array[i - 1];
			}
			current = array[i];
			count = 1;
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