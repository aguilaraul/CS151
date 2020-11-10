/**
 * Raul Aguilar
 * November 9, 2020
 * CS 151 3228 Midterm Problem 3
 */
#include <iostream>
#include <iomanip>
using namespace std ;

struct Customer {
    string name ;
    double balance ;

    Customer(const string& n, double b) {
        this->name = n;
        this->balance = b;
    }
};

void bubbleSort(Customer[], int);

int main() {

    // Create an array of 10 Customer objects in random order
    Customer data[] = {
            Customer("XYZ Company", 2043.51),
            Customer("Diddy Daddy", 5178.31),
            Customer("Everready", 29240.25),
            Customer("Washburn Ltd.", 13195.40),
            Customer("Joe Jackson", 1442.00),
            Customer("BubbleWorks", -295.40),
            Customer("Alex P. Jones", 6110.68),
            Customer("Sammy Sosa", 999.99),
            Customer("Timberworks", 17201.89),
            Customer("Microvision", 14040.71)
    } ;

    // Create an array pData of pointers into the data array and initialize
    // so that pData[k] points to data[k]
    Customer* pData[10];
    for(int i = 0; i < 10; i++) {
        pData[i] = &data[i];
    }

    // Sort the pData array so that the Customer with the largest balance is
    // first, and the Customer with the smallest balance is last
    bubbleSort(data, 10);

    // Print the Customer structures in the order in which they appear in pData
    cout << "      Name          Balance" << endl
         << "----------------  -----------" << endl
         << fixed << setprecision(2);
    for(auto & i : data) {
        cout << left << setw(16) << i.name << " ";
        cout << right << setw(11) << i.balance << endl;
    }
    cout << endl;
}

void bubbleSort(Customer array[], int size) {
    bool madeSwap = true;
    for(int maxElement = size - 1; maxElement > 0 && madeSwap; maxElement--) {
        madeSwap = false;
        for(int i = 0; i < maxElement; i++) {
            if(array[i].balance < array[i+1].balance) {
                swap(array[i], array[i+1]);
                madeSwap = true;
            }
        }
    }
}

void swap(Customer &a, Customer &b) {
    Customer temp = a;
    a = b;
    b = temp;
}


