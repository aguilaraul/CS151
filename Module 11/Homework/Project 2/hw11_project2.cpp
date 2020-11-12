/**
 * hw11_project2.cpp
 * Author:  Raul Aguilar
 * Date:    November 12, 2020
 * CS 151 3228 Module 11 Homework 11 Project 2
 * Write a recursive Boolean function named isMember. The function
 * should accept three parameters: an array of integers, an integer
 * indicating the number of elements in the array, and an integer value
 * to be searched for. The function should return true if the value is
 * found in the array or false if the value is not found.
 *
 * Algorithm:
 * Base case: if scanning the last element in the array is not the value it's
 * searching for, then return false; value is not in the array
 * Otherwise, if current element scanned is equal to value, then return
 * true; the value was found
 * Else, call function again with size-1
 */
#include <iostream>
using namespace std;

bool isMember(int[], int, int);

int main() {
    // Get size of the array
    int size = 1, find = 0;
    cout << "Enter the size of the array:" << endl;
    cin >> size;
    int* arr = new int[size];

    // Fill the array
    cout << "Enter numbers to fill the array:" << endl;
    for(int i = 0; i < size;i++) {
        cin >> *(arr+i);
    }

    // Value to search for
    cout << "Enter a value to look for:" << endl;
    cin.ignore();
    cin >> find;

    // Determine if value is in the array
    if(isMember(arr, size, find)) {
        cout << find << " is in the array." << endl;
    } else {
        cout << find << " is not in the array." << endl;
    }

    delete [] arr;
    return 0;
}

bool isMember(int arr[], int size, int find) {
    // If last element in array is not equal to value
    // then return false
    if(size == 1 && arr[0] != find) {
        return false;
    }

    // If value was found in current element, return true
    // Otherwise, run again with size-1
    if(arr[size] == find) {
        return true;
    } else {
        return isMember(arr, size-1, find);
    }
}