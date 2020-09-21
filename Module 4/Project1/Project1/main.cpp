/*
 * main.cpp
 * Use an array of unique pointers to mange a structure
 * of Stones.
 *
 * author   Raul Aguilar
 * date     September 20, 2020
 *
 * CS 151 Module 4 Project 1
 * After buying a display box with 10 empty slots, you decide to put
 * your 10 best stones (lettered A, B, C, ... J) by selecting a slot
 * randomly for each stone until finding an empty slot. For each stone,
 * record the number of attempts it took to find an empty slot for that
 * stone.
 *
 * Algorithm:
 * 1. Create Stone struct with stone letter and number of attempts to
 * find an empty slot.
 * 2. Set random seed for random number generator
 * 3. Create an array of 10 unique pointers to Stone objects
 * 4. For a single stone:
 *      a. Generate a random slot index to insert stone into
 *      b. If current slot is not assigned, then empty slot has been
 *      found. Create new Stone object with current letter and number
 *      of attempts, and assign it to the available slot.
 *      c. Otherwise, increment number of attempts and generate new
 *      random index
 * 5. Print report showing the slot numbers, the stone letter and
 * number of attempts with a total of attempts below the list.
 */
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

struct Stone
{
    char slot;
    int attempts;
    Stone()
    {
        slot = NULL;
        attempts = 0;
    }
    Stone(char s, int a)
    {
        slot = s;
        attempts = a;
    }
};


int main()
{
    srand(time(NULL));
    unique_ptr<Stone> box[10];
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
    cout << setw(4) << "Slot";
    cout << setw(5) << " Stone";
    cout << setw(7) << " Attempts" << endl;
    cout << "---- ----- -------" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << setw(4) << i;
        cout << setw(5) << box[i]->slot;
        cout << setw(7) << box[i]->attempts << endl;
        totalAttempts += box[i]->attempts;
    }
    cout << endl;
    cout << "Total Attempts: " << totalAttempts << endl;

    return 0;
}
