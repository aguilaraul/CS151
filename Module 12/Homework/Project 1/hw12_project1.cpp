/**
 * hw12_project1.cpp
 * Author:  Raul Aguilar
 * Date:    November 15, 2020
 * CS 151 3228 Module 12 Homework 12 Project 1
 * Design a class named AbstractSort that can be used to analyze the
 * number of comparisons performed by a sorting algorithm.
 * 
 * Algorithm:
 * 
 */
#include <iostream>
#include <time.h>
using namespace std;

class AbstractSort {
    protected:
    unsigned long int comparisons;
    void compare(int &n1, int &n2, bool &madeSwap) {
        if(n1 > n2) {
            swap(n1, n2);
            madeSwap = true;
        }
        ++comparisons;
    }
    void swap(int &n1, int &n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    public:
    virtual void sort(int[], int) = 0;
    unsigned long getComparisons() const {
        return comparisons;
    }
};

class BubbleSort : public AbstractSort {
    public:
    void sort(int arr[], int size) override {
        bool madeSwap = true;
        for(int maxElement = size-1; maxElement > 0 && madeSwap; maxElement--) {
            madeSwap = false;
            for(int i = 0; i < maxElement; i++) {
                compare(arr[i], arr[i+1], madeSwap);
            }
        }
    }
};

int main() {
    srand(time(nullptr));
    const int SIZE = 10;
    int numArr[SIZE];
    BubbleSort bs;

    // Populate array with random numbers
    cout << "Before sorting:\n";
    for(int & i : numArr) {
        i = rand() % 100;
        cout << i << " ";
    }
    cout << endl;

    // Bubble sort the array
    bs.sort(numArr, SIZE);

    // Print the sorted array
    cout << "After sorting:\n";
    for(int i:numArr) {
        cout << i <<  " ";
    }
    cout << endl;

    // Display number of comparisons
    cout << "Comparisons: " << bs.getComparisons() << endl;
    return 0;
}