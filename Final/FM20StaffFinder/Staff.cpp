//
// Created by raula on 11/7/2020.
//

#include "Staff.h"

Staff::Staff() :
    Person()
{
    setRole("");
    setClub("");
}

Staff::Staff(const string &nation, const string &name, int age,
             const string &role, const string &club) :
    Person(nation, name, age)
{
    setRole(role);
    setClub(club);
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

string Staff::to_string() {
    return Person::to_string() +
    " They are currently a " + role +
    " at " + club + '.';
}

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
