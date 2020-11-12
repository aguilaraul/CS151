/**
 * hw11_project1.cpp
 * Author:  Raul Aguilar
 * Date:    November 12, 2020
 * CS 151 3228 Module 11 Homework 11 Project 1
 * Write an iterative version (using a loop instead of recursion) of
 * the factorial function.
 *
 * Algorithm:
 *
 */
#include <iostream>
using namespace std;

unsigned long long int iterativeFactorial(int);

int main() {
    int num = 0;
    cout << "Enter a number to find it factorial:\n";
    cin >> num;

    unsigned long long int fact2 = iterativeFactorial(num);

    cout << "Factorial of " << num << " is " << fact2 << endl;

    return 0;
}

unsigned long long int iterativeFactorial(int n) {
    unsigned long long int fact = 1;
    if(n==0) {
        return fact;
    } else {
        for(int i = 2; i <= n; i++) {
            fact *= i;
        }
    }
    return fact;
}