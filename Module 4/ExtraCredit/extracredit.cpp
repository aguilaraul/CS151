/*
 * extracredit.cpp
 *
 * author   Raul Aguilar
 * date     September 22, 2020
 *
 * CS 151 3228 Module 4 Extra Credit
 * Sort the array of pointers used in Project 1 by stone's letter.
 *
 * Algorithm:
 *
 */
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

struct Stone
{
    char letter;
    int attempts;
    Stone()
    {
        letter = '\0';
        attempts = 0;
    }
    Stone(char l, int a)
    {
        letter = l;
        attempts = a;
    }
};

void printDisplayBox(unique_ptr<Stone>[]);
void bubbleSort(unique_ptr<Stone>[]);
void swap(unique_ptr<Stone>, unique_ptr<Stone>);

const int SIZE = 10;

int main()
{
    srand(time(NULL));
    unique_ptr<Stone> box[SIZE];
    int attempts, index;
    int totalAttempts = 0;
    bool foundSlot;

    // For each stone A-J
    for(char letter = 65; letter < 75; letter++)
    {
        // Reset found slot and number of attempts
        foundSlot = false;
        attempts = 1;
        while(!foundSlot)
        {
            index = rand() % 10;
            // If current slot has not been assigned yet, empty slot
            // is found
            if(box[index].get() == nullptr)
            {
                unique_ptr<Stone> newStone(new Stone(letter, attempts));
                box[index] = move(newStone);
                foundSlot = true;
            }
            // Increment number of attempts if current slot is already
            // assigned
            attempts++;
        }
    }

    // Print stones
    printDisplayBox(move(box));

    // Sort box by letter
    bubbleSort(move(box));

    //Print after sort
    printDisplayBox(move(box));

    return 0;
}

void printDisplayBox(unique_ptr<Stone> box[])
{
    int totalAttempts = 0;
        // Print stones
    cout << setw(4) << "Slot";
    cout << setw(5) << " Stone";
    cout << setw(7) << " Attempts" << endl;
    cout << "---- ----- -------" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << setw(4) << i;
        cout << setw(5) << box[i]->letter;
        cout << setw(7) << box[i]->attempts << endl;
        totalAttempts += box[i]->attempts;
    }
    cout << endl;
    cout << "Total Attempts: " << totalAttempts << endl;
}

void bubbleSort(unique_ptr<Stone> box[])
{
    bool madeSwap = false;
    for(int maxElement = SIZE - 1; maxElement > 0 && madeSwap; maxElement--)
    {
        madeSwap = false;
        for(int i = 0; i < maxElement; i++)
        {
            if(box[i]->letter > box[i+1]->letter)
            {
                swap(move(box[i]), move(box[i+1]));
                madeSwap = true;
            }
        }
    }
}

void swap(unique_ptr<Stone> a, unique_ptr<Stone> b)
{
    unique_ptr<Stone> temp = make_unique<Stone>();
    temp = move(a);
    a = move(b);
    b = move(temp);
}
