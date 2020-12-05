/**
 * Staff.h
 * Author   Raul Aguilar
 * Date     December 3, 2020
 * CS 151 3228 Final Project
 */

#ifndef FM20SCOUT_STAFF_H
#define FM20SCOUT_STAFF_H
#include "Person.h"
#include <memory>
#include <iomanip>
#include <fstream>
using namespace std;

class Staff : public Person {
private:
    short int StaffAttributes[25] = {};
    enum attributes
    {
        attacking, defending, fitness, mental, tactical, technical, workingWithYoungsters,
        physiotherapy, sportsScience,
        gkDistribution, gkHandling, gkShotStop,
        adaptability, determination, discipline, manManagement, motivating,
        judgingPlayerData, judgingTeamData, presentingData,
        judgingAbility, judgingPotential, judgingStaffAbility, negotiating, tacticalKnowledge
    };

    struct StaffAttributes_ {
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


    void saveToFile() const;
    void saveToBinary();

    void readFromBinary(fstream &);

    // Attributes
    void setCoaching(const short&, const short&, const short&, const short&,
                     const short&, const short&, const short&);
    void setMedical(const short&, const short&);
    void setGoalKeeping(const short&, const short&, const short&);
    void setMental(const short&, const short&, const short&, const short&,
                   const short&);
    void setScouting(const short&, const short&, const short&);
    void setKnowledge(const short&, const short&, const short&,
                      const short&, const short&);
    string to_string() override;
};


#endif //FM20SCOUT_STAFF_H
