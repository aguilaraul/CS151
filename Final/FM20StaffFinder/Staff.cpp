//
// Created by raula on 11/7/2020.
//

#include "Staff.h"

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

//
// @Incomplete: Fix attributes display
//
void Staff::printAttributes() const {
    cout << "Nation: " << nation << endl;
    cout << left << setw(6) << "Name:";
    cout << setw(25) << name;
    cout << right << setw(10) << "Role: " << role << endl;
    cout << left << setw(6) << "Age: ";
    cout << setw(25) << age;
    cout << right << setw(10) << "Club: " << club << endl;

    int headingWidth = 30, spaceBetween = 5, attributeWidth = 2;
    // Coaching & Mental
    cout << left << setw(headingWidth) << "Coaching";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Mental" << endl;

    cout << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << Attributes.attacking;
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << Attributes.adaptability << endl;

    cout << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << Attributes.defending;
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Determination:"<< setw(attributeWidth) << Attributes.determination << endl;

    cout << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << Attributes.fitness;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << Attributes.discipline << endl;

    cout << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << Attributes.mental;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << Attributes.manManagement << endl;

    cout << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << Attributes.tactical;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << Attributes.motivating << endl;

    cout << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << Attributes.technical << endl;
    cout << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << Attributes.workingWithYoungsters << endl;

    // Medical & Scouting
    cout << left << setw(headingWidth) << "Medical";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Scouting" << endl;

    cout << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << Attributes.physiotherapy;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << Attributes.judgingPlayerData << endl;

    cout << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << Attributes.sportsScience;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << Attributes.judgingTeamData << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << Attributes.presentingData << endl;

    // GK Coaching & Knowledge
    cout << left << setw(headingWidth) << "GK Coaching";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Knowledge" << endl;

    cout << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << Attributes.gkDistribution;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << Attributes.judgingAbility << endl;

    cout << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << Attributes.gkHandling;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << Attributes.judgingPotential << endl;

    cout << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << Attributes.gkShotStop;
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << Attributes.judgingStaffAbility << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << Attributes.negotiating << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << Attributes.tacticalKnowledge << endl;
}

void Staff::saveToFile() {
    const string fileName = name + ".txt";
    ofstream outfile(fileName, ios::out);
    outfile << "Nation: " << nation << endl;
    outfile << left << setw(6) << "Name:";
    outfile << setw(25) << name;
    outfile << right << setw(10) << "Role: " << role << endl;
    outfile << left << setw(6) << "Age: ";
    outfile << setw(25) << age;
    outfile << right << setw(10) << "Club: " << club << endl;

    int headingWidth = 30, spaceBetween = 5, attributeWidth = 2;
    // Coaching & Mental
    outfile << left << setw(headingWidth) << "Coaching";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Mental" << endl;

    outfile << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << Attributes.attacking;
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << Attributes.adaptability << endl;

    outfile << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << Attributes.defending;
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Determination:"<< setw(attributeWidth) << Attributes.determination << endl;

    outfile << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << Attributes.fitness;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << Attributes.discipline << endl;

    outfile << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << Attributes.mental;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << Attributes.manManagement << endl;

    outfile << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << Attributes.tactical;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << Attributes.motivating << endl;

    outfile << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << Attributes.technical << endl;
    outfile << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << Attributes.workingWithYoungsters << endl;

    // Medical & Scouting
    outfile << left << setw(headingWidth) << "Medical";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Scouting" << endl;

    outfile << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << Attributes.physiotherapy;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << Attributes.judgingPlayerData << endl;

    outfile << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << Attributes.sportsScience;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << Attributes.judgingTeamData << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << Attributes.presentingData << endl;

    // GK Coaching & Knowledge
    outfile << left << setw(headingWidth) << "GK Coaching";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Knowledge" << endl;

    outfile << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << Attributes.gkDistribution;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << Attributes.judgingAbility << endl;

    outfile << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << Attributes.gkHandling;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << Attributes.judgingPotential << endl;

    outfile << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << Attributes.gkShotStop;
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << Attributes.judgingStaffAbility << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << Attributes.negotiating << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << Attributes.tacticalKnowledge << endl;
    outfile.close();
}

void Staff::saveToBinary() {
    const string fileName = name + ".dat";
    ofstream dataFile(fileName, ios::binary | ios::out);

    // Person data
    dataFile.write(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&name), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&age), sizeof(int));
    dataFile.write(reinterpret_cast<char*>(&role), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&club), sizeof(string));

    // Attributes
    // Coaching
    dataFile.write(reinterpret_cast<char*>(&Attributes.attacking), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.defending), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.fitness), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.mental), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.tactical), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.technical), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.workingWithYoungsters), sizeof(short int));

    // Medical
    dataFile.write(reinterpret_cast<char*>(&Attributes.physiotherapy), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.sportsScience), sizeof(short int));

    // GK Coaching
    dataFile.write(reinterpret_cast<char*>(&Attributes.gkDistribution), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.gkHandling), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.gkShotStop), sizeof(short int));

    // Mental
    dataFile.write(reinterpret_cast<char*>(&Attributes.adaptability), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.determination), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.discipline), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.manManagement), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.motivating), sizeof(short int));

    // Scouting
    dataFile.write(reinterpret_cast<char*>(&Attributes.judgingPlayerData), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.judgingTeamData), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.presentingData), sizeof(short int));

    // Knowledge
    dataFile.write(reinterpret_cast<char*>(&Attributes.judgingAbility), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.judgingPotential), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.judgingStaffAbility), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.negotiating), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&Attributes.tacticalKnowledge), sizeof(short int));

    dataFile.close();
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

void Staff::setMental(short adapt, short det, short disc, short mm, short mot) {
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

void Staff::setKnowledge(short jA, short jP, short jSA, short n, short tK) {
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