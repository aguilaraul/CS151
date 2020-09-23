#include <iostream>
#include <vector>

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
    vector<Member*> members;
    members.push_back(new Member("Oprah Winfrey", 'P'));
    members.push_back(new Member("Fluffy Iglesias", 'P'));
    members.push_back(new Member("Charlie Sheen", 'B'));
    members.push_back(new Member("Bill Gates", 'B'));

    for(Member *m:members)
    {
        cout << m->name << endl;
        cout << m->type << endl;
    }

    return 0;
}

void visit(Member* m)
{
    ++m->totalVisits;
    ++m->visits;
}
