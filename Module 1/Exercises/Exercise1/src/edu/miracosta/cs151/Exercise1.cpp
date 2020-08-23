// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;

int warmest_month(int temps[]);

int main() {
    string month_names[] = { "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December" };
    int temperature[] = { 38, 42, 50, 61, 72, 79, 84, 83, 75, 64, 54, 43 };

    cout << "The warmest month is " << temperature[warmest_month(temperature)] << endl;
}

int warmest_month(int temps[]) {
    int warmest = temps[0];

    for(int i = 1; i < (sizeof(temps)/sizeof(temps[0])); i++) {
        if (warmest < temps[i]) {
            warmest = temps[i];
        }
    }

    return warmest;
}