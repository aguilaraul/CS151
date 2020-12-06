/**
 * Staff.h
 * Author   Raul Aguilar
 * Date     December 3, 2020
 * CS 151 3228 Final Project
 */

#ifndef FM20SCOUT_STAFF_H
#define FM20SCOUT_STAFF_H
#include "Person.h"
using namespace std;

class Staff : public Person {
private:
    int numOfAttributes= 25;
    short int StaffAttributes[25] = {};
    enum attributes
    {
        // Coaching
        ATTACKING, DEFENDING, FITNESS, MENTAL, TACTICAL, TECHNICAL, WORKINGWITHYOUNGSTERS,
        // Medical
        PHYSIOTHERAPY, SPORTSSCIENCE,
        // GK Coaching
        GKDISTRIBUTION, GKHANDLING, GKSHOTSTOP,
        // Mental
        ADAPTABILITY, DETERMINATION, DISCIPLINE, MANMANAGEMENT, MOTIVATING,
        // Scouting
        JUDGINGPLAYERDATA, JUDGINGTEAMDATA, PRESENTINGDATA,
        // Knowledge
        JUDGINGABILITY, JUDGINGPOTENTIAL, JUDGINGSTAFFABILITY, NEGOTIATING, TACTICALKNOWLEDGE
    };

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

    string to_string() override;
    void compare(Staff&);

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
};


#endif //FM20SCOUT_STAFF_H
