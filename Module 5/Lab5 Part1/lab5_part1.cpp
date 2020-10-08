/*
 * lab5_part1.cpp
 *
 * author   Raul Aguilar
 * date     October 7, 2020
 *
 * CS 151 3228 Module 5 Lab 5 Part 1
 * Create a class that tracks memberships in a gym.
 *
 * Algorithm:
 * 1. Create a function named visit that increments the number of
 * visits for a member and for the gym.
 * 2. Create a vector of pointers to Member structure
 * 3. Create a Member object using the new operator and add pointers to
 * four members
 * 4. Delete the pointer to Charlie's Member object from the vector
 * 5. Delete Charlie's Member object from the heap
 * 6. For each of the three remaining members generate a random number
 * between 5 and 20, and call the visit function for that member that
 * many times
 * 7. Print a report which loops through the vector printing each
 * members id, name, number of visits, and monthly rate.
 * 8. Print the total number of visits to the gym and the number of
 * active members.
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

const double BASIC_RATE = 28.50,
             PREMIUM_RATE = 60.00;

struct Member
{
    static int totalVisits, activeMembers, lastId;
    int id;
    string name;
    char type;
    int visits;
    Member(string name, char type)
    {
        this->name = name;
        this->type = type;
        activeMembers++;
        id = lastId++;
    }
    ~Member()
    {
        activeMembers--;
    }
};

// Define static variables
int Member::totalVisits = 0;
int Member::activeMembers = 0;
int Member::lastId = 100000;

// Function Prototypes
void visit(Member*);

int main()
{
    srand(time(NULL));
    vector<Member*> members;

    // Add member to vector
    members.push_back(new Member("Oprah Winfrey", 'P'));
    members.push_back(new Member("Fluffy Iglesias", 'P'));
    members.push_back(new Member("Charlie Sheen", 'B'));
    members.push_back(new Member("Bill Gates", 'B'));

    // Delete Charlie Sheen
    delete members[2];
    members.erase(members.begin()+2);

    // Generate random number of visits for each remaining member
    for(vector<Member*>::iterator it = members.begin(); it != members.end(); ++it)
    {
        int visits = 5 + (rand() % (20 - 5 + 1));
        for(int j = visits; j > 0; j--)
        {
            visit(*it);
        }
    }


    cout << left << setw(6) << "ID";
    cout << setw(18) << " Name";
    cout << setw(13) << " Visits";
    cout << " Monthly Rate" << endl;
    for(int i = 0; i < 50; i++)
    {
      cout << "-";
    }
    cout << endl;
    for(Member *m:members)
    {
      cout << m->id;
      cout << " " << setw(18) << m->name;
      cout << " " << setw(13) << m->visits;
      cout << " ";
      if(m->type == 'P')
      {
        cout << setw(6) << setprecision(2) << fixed << PREMIUM_RATE << endl;
      }
      else
      {
        cout << setw(6) << BASIC_RATE << endl;
      }
    }

    cout << endl;
    cout << "Total visits: " << members[0]->totalVisits << endl;
    cout << "Active members: " << members[0]->activeMembers << endl;

    return 0;
}

void visit(Member* m)
{
    m->totalVisits++;
    m->visits++;
}
