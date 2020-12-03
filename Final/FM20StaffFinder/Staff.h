//
// Created by raula on 11/7/2020.
//

#ifndef FM20SCOUT_STAFF_H
#define FM20SCOUT_STAFF_H
#include "Person.h"
#include <memory>
#include <iomanip>
#include <fstream>
using namespace std;

class Staff : public Person {
private:
    struct StaffAttributes {
        // Coaching
        short int attacking, defending, fitness, mental, tactical,
            technical, workingWithYoungsters;
        // Medical
        short int physiotherapy, sportsScience;
        // GK Coaching
        short int gkDistribution, gkHandling, gkShotStop;
        // Mental
        short int adaptability, determination, discipline,
            manManagement, motivating;
        // Scouting
        short int judgingPlayerData, judgingTeamData, presentingData;
        // Knowledge
        short judgingAbility, judgingPotential, judgingStaffAbility,
            negotiating, tacticalKnowledge;
    } Attributes;

protected:
    string role;
    string club;
    void setRandomAttributes();
public:
    Staff();
    Staff(const string&, const string&, int,
          const string&, const string&);
    ~Staff();
    void setRole(const string&);
    void setClub(const string&);
    string getRole();
    string getClub();
    void printAttributes() const;
    void saveToFile();
    void saveToBinary();
    // Attributes
    void setCoaching(short int, short int, short int,
                     short int, short int, short int, short int);
    void setMedical(short int, short int);
    void setGoalKeeping(short int, short int, short int);
    void setMental(short int, short int, short int, short int,
                   short int);
    void setScouting(short int, short int, short int);
    void setKnowledge(short int, short int, short int,
                      short int, short int);
    string to_string() override;
};


#endif //FM20SCOUT_STAFF_H
