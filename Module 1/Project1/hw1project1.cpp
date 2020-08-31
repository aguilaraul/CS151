/*
 * author   Raul Aguilar
 * date     September 01, 2020
 * 
 * CS 151 3228 Homework 1 Project 1
 * Use a vector to sort numbers. The purpose of this project is to
 * generate thirty random whole numbers between 1 and 10, insert them
 * into a vector in descending order, then and print the numbers in
 * ascending order.
 * 
 * Algorithm:
 * 1. Change seed for random number generation
 * 2. Create an empty int vector and iterator
 * 3. Use while loop to fill array with random numbers until size == 30
 *  3a. Use rand to generate random number
 *  3b. Reset index after each insertion
 *  3c. Use for-loop to find element in vector that is smaller than
 *      random number, record index of smaller value
 *  3d. Use index and iterator to insert random number into the correct
 *      location
 * 4. Display results
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    // Change seed of random number generator
    srand(time(NULL));
    vector<int> numbers;
    vector<int>::iterator iter;

    // Fill vector with random numbers until size == 30
    while(numbers.size() < 30) {
        int index = 0;
        int random_number = (rand() % RAND_MAX) % 10;
        
        // Scan vector until the element is less than the random number
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] > random_number) {
                // index+1 to get the spot after the smaller value
                index = i+1;
            }
        }

        // An iterator to insert the random number
        iter = numbers.begin() + index;
        numbers.insert(iter, random_number);
    }

    // Displaying numbers in vector

    cout << "Descending Order:" << endl;
    for(int num:numbers) {
        cout << num << ' ';
    }
    cout << endl;

    cout << "Accending Order:" << endl;
    while(!numbers.empty()) {
        numbers.pop_back();
        cout << numbers[numbers.size()] << ' ';
    }
    cout << endl;

    return 0;
}