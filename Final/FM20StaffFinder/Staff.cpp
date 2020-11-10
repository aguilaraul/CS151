//
// Created by raula on 11/7/2020.
//

#include "Staff.h"
#include <memory>

Staff::Staff()
    : Person()
{
    setRole("");
    setClub("");
    setRandomAttributes();
}

Staff::Staff(const string &nation, const string &name, int age,
             const string &role, const string &club) :
    Person(nation, name, age)
{
    setRole(role);
    setClub(club);
    setRandomAttributes();
}

Staff::~Staff() = default;

void Staff::setRole(const string &r) {
    this->role = r;
}

void Staff::setClub(const string &c) {
    this->club = c;
}

string Staff::getRole() {
    return role;
}

string Staff::getClub() {
    return club;
}

void Staff::printAttributes() const {
    cout << "Coaching";
    cout << '\n' << "Attacking:\t" << Attributes.attacking;
    cout << '\n' << "Defending:\t" << Attributes.defending;
    cout << '\n' << "Fitness:\t" << Attributes.fitness;
    cout << '\n' << "Mental:\t" << Attributes.mental;
    cout << '\n' << "Tactical:\t" << Attributes.tactical;
    cout << '\n' << "Technical:\t" << Attributes.technical;
    cout << '\n' << "Working With Youngster:\t" << Attributes.workingWithYoungsters;
    cout << endl;
    cout << "Medical";
    cout << '\n' << "Physiotherapy:\t" << Attributes.physiotherapy;
    cout << '\n' << "Sports Science:\t" << Attributes.sportsScience;
    cout << endl;
}

string Staff::to_string() {
    return Person::to_string() +
    " They are currently a " + role +
    " at " + club + '.';
}

/* Attributes */

void Staff::setCoaching(short attack, short defend, short fit, short ment,
                        short tact, short tech, short wy) {
    Attributes.attacking = attack;
    Attributes.defending = defend;
    Attributes.fitness = fit;
    Attributes.mental = ment;
    Attributes.tactical = tact;
    Attributes.technical = tech;
    Attributes.workingWithYoungsters = wy;
}

void Staff::setMedical(short physio, short ss) {
    Attributes.physiotherapy = physio;
    Attributes.sportsScience = ss;
}

void Staff::setGoalKeeping(short dist, short hand, short ss) {
    Attributes.gkDistribution = dist;
    Attributes.gkHandling = hand;
    Attributes.gkShotStop = ss;
}

void Staff::setMental(short adapt, short det, short disc, short mm,
                      short mot) {
    Attributes.adaptability = adapt;
    Attributes.determination = det;
    Attributes.discipline = disc;
    Attributes.manManagement = mm;
    Attributes.motivating = mot;
}

void Staff::setScouting(short jPD, short jTD, short pD) {
    Attributes.judgingPlayerData = jPD;
    Attributes.judgingTeamData = jTD;
    Attributes.presentingData = pD;
}

void Staff::setKnowledge(short jA, short jP, short jSA, short n,
                         short tK) {
    Attributes.judgingAbility = jA;
    Attributes.judgingPotential = jP;
    Attributes.judgingStaffAbility = jSA;
    Attributes.negotiating = n;
    Attributes.tacticalKnowledge = tK;
}

void Staff::setRandomAttributes() {
    // Set coaching
    unique_ptr<int[]> att(new int[7]);
    for(int i = 0; i < 7; i++) {
        att[i] = rand() % 20 + 1;
    }
    setCoaching(att[0], att[1],att[2], att[3],
                att[4], att[5], att[6]);
    // Set Medical
    att = make_unique<int[]>(2);
    for(int i = 0; i < 2; i++) {
        att[i] = rand() % 20 + 1;
    }
    setMedical(att[0], att[1]);
    // Set Goalkeeping
    att = make_unique<int[]>(3);
    for(int i = 0; i < 3; i++) {
        att[i] = rand() % 20 + 1;
    }
    setGoalKeeping(att[0], att[1], att[2]);
    // Set Mental
    att = make_unique<int[]>(5);
    for(int i = 0; i < 5; i++) {
        att[i] = rand() % 20 + 1;
    }
    setMental(att[0], att[1], att[2], att[3], att[4]);
    // Set Scouting
    att = make_unique<int[]>(3);
    for(int i = 0; i < 3; i++) {
        att[i] = rand() % 20 + 1;
    }
    setScouting(att[0], att[1], att[2]);
    // Set Knowledge
    att = make_unique<int[]>(5);
    for(int i = 0; i < 5; i++) {
        att[i] = rand() % 20 + 1;
    }
    setKnowledge(att[0], att[1], att[2], att[3], att[4]);
}