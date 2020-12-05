/**
 * Staff.cpp
 * Author   Raul Aguilar
 * Date     December 3, 2020
 * CS 151 3228 Final Project
 */

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

    cout << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << StaffAttributes[attacking];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << StaffAttributes[adaptability] << endl;

    cout << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << StaffAttributes[defending];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Determination:"<< setw(attributeWidth) << StaffAttributes[determination] << endl;

    cout << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << StaffAttributes[fitness];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << StaffAttributes[discipline] << endl;

    cout << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << StaffAttributes[mental];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << StaffAttributes[manManagement] << endl;

    cout << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << StaffAttributes[tactical];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << StaffAttributes[motivating] << endl;

    cout << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << StaffAttributes[technical] << endl;
    cout << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << StaffAttributes[workingWithYoungsters] << endl;

    // Medical & Scouting
    cout << left << setw(headingWidth) << "Medical";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Scouting" << endl;

    cout << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << StaffAttributes[physiotherapy];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << StaffAttributes[judgingPlayerData] << endl;

    cout << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << StaffAttributes[sportsScience];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << StaffAttributes[judgingTeamData] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << StaffAttributes[presentingData] << endl;

    // GK Coaching & Knowledge
    cout << left << setw(headingWidth) << "GK Coaching";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Knowledge" << endl;

    cout << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << StaffAttributes[gkDistribution];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << StaffAttributes[judgingAbility] << endl;

    cout << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << StaffAttributes[gkHandling];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << StaffAttributes[judgingPotential] << endl;

    cout << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << StaffAttributes[gkShotStop];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << StaffAttributes[judgingStaffAbility] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << StaffAttributes[negotiating] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << StaffAttributes[tacticalKnowledge] << endl;
}

void Staff::saveToFile() const {
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

    outfile << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << StaffAttributes[attacking];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << StaffAttributes[adaptability] << endl;

    outfile << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << StaffAttributes[defending];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Determination:"<< setw(attributeWidth) << StaffAttributes[determination] << endl;

    outfile << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << StaffAttributes[fitness];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << StaffAttributes[discipline] << endl;

    outfile << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << StaffAttributes[mental];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << StaffAttributes[manManagement] << endl;

    outfile << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << StaffAttributes[tactical];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << StaffAttributes[motivating] << endl;

    outfile << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << StaffAttributes[technical] << endl;
    outfile << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << StaffAttributes[workingWithYoungsters] << endl;

    // Medical & Scouting
    outfile << left << setw(headingWidth) << "Medical";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Scouting" << endl;

    outfile << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << StaffAttributes[physiotherapy];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << StaffAttributes[judgingPlayerData] << endl;

    outfile << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << StaffAttributes[sportsScience];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << StaffAttributes[judgingTeamData] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << StaffAttributes[presentingData] << endl;

    // GK Coaching & Knowledge
    outfile << left << setw(headingWidth) << "GK Coaching";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Knowledge" << endl;

    outfile << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << StaffAttributes[gkDistribution];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << StaffAttributes[judgingAbility] << endl;

    outfile << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << StaffAttributes[gkHandling];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << StaffAttributes[judgingPotential] << endl;

    outfile << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << StaffAttributes[gkShotStop];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << StaffAttributes[judgingStaffAbility] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << StaffAttributes[negotiating] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << StaffAttributes[tacticalKnowledge] << endl;
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

    //Attributes
    for(auto & StaffAttribute : StaffAttributes) {
        dataFile.write(reinterpret_cast<char*>(&StaffAttribute), sizeof(short int));
    }


    // Coaching
    /*
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[0]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[1]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[2]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[3]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[4]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[5]), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes[6]), sizeof(short int));

    // Medical
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.physiotherapy), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.sportsScience), sizeof(short int));

    // GK Coaching
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.gkDistribution), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.gkHandling), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.gkShotStop), sizeof(short int));

    // Mental
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.adaptability), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.determination), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.discipline), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.manManagement), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.motivating), sizeof(short int));

    // Scouting
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.judgingPlayerData), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.judgingTeamData), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.presentingData), sizeof(short int));

    // Knowledge
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.judgingAbility), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.judgingPotential), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.judgingStaffAbility), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.negotiating), sizeof(short int));
    dataFile.write(reinterpret_cast<char*>(&StaffAttributes.tacticalKnowledge), sizeof(short int));
     */
    dataFile.close();
}

void Staff::readFromBinary(fstream& dataFile) {
    fstream &dataFileCopy = dataFile;
    dataFileCopy.read(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&name), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&age), sizeof(int));
    dataFileCopy.read(reinterpret_cast<char*>(&role), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&club), sizeof(string));

    cout << name << "<-- Here ::" << endl;

    for(auto & StaffAttribute : StaffAttributes) {
        dataFileCopy.read(reinterpret_cast<char*>(&StaffAttribute), sizeof(short int));
    }

    dataFileCopy.close();
}

string Staff::to_string() {
    return Person::to_string() +
    " They are currently a " + role +
    " at " + club + '.';
}



/* Set Attributes */

void Staff::setCoaching(const short &attack, const short &defend, const short &fit,
                        const short &ment, const short &tact, const short &tech,
                        const short &workingWYoungsters)
{
    StaffAttributes[attacking] = attack;
    StaffAttributes[defending] = defend;
    StaffAttributes[fitness] = fit;
    StaffAttributes[mental] = ment;
    StaffAttributes[tactical] = tact;
    StaffAttributes[technical] = tech;
    StaffAttributes[workingWithYoungsters] = workingWYoungsters;
}

void Staff::setMedical(const short &physio, const short &ss)
{
    StaffAttributes[physiotherapy] = physio;
    StaffAttributes[sportsScience] = ss;
}

void Staff::setGoalKeeping(const short& dist, const short& hand, const short& ss)
{
    StaffAttributes[gkDistribution] = dist;
    StaffAttributes[gkHandling] = hand;
    StaffAttributes[gkShotStop] = ss;
}

void Staff::setMental(const short& adapt, const short& det, const short& disc,
                      const short& mm, const short& mot)
{
    StaffAttributes[adaptability] = adapt;
    StaffAttributes[determination] = det;
    StaffAttributes[discipline] = disc;
    StaffAttributes[manManagement] = mm;
    StaffAttributes[motivating] = mot;
}

void Staff::setScouting(const short& jPD, const short& jTD, const short& pD)
{
    StaffAttributes[judgingPlayerData] = jPD;
    StaffAttributes[judgingTeamData] = jTD;
    StaffAttributes[presentingData] = pD;
}

void Staff::setKnowledge(const short& jA, const short& jP, const short& jSA,
                         const short& n, const short& tK)
{
    StaffAttributes[judgingAbility] = jA;
    StaffAttributes[judgingPotential] = jP;
    StaffAttributes[judgingStaffAbility] = jSA;
    StaffAttributes[negotiating] = n;
    StaffAttributes[tacticalKnowledge] = tK;
}

void Staff::setRandomAttributes() {
    for(short & StaffAttribute : StaffAttributes) {
        StaffAttribute = rand() % 20 + 1;
    }
}
