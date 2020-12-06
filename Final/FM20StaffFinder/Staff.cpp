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

string Staff::to_string() {
    return Person::to_string() +
           " They are currently a " + role +
           " at " + club + '.';
}

void Staff::compare(Staff &other) {
    string attribute[] = {
            "Attacking:", "Defending:", "Fitness:", "Mental:", "Tactical:",
            "Technical:", "Working With Youngsters:",
            "Physiotherapy:", "Sports Science:",
            "GK Distribution:", "GK Handling:", "GK Shot Stop:",
            "Adaptability:", "Determination:", "Level of Discipline:", "Man Management:",
            "Motivating:",
            "Judging Player Data:", "Judging Team Data:", "Presenting Data:",
            "Judging Ability:", "Judging Potential:", "Judging Staff Ability:",
            "Negotiating:", "Tactical Knowledge:"
    };
    int staff1Won = 0, staff2Won = 0;
    short higher;
    string winner;
    for(int i = 0; i < numOfAttributes; i++) {
        if(this->StaffAttributes[i] > other.StaffAttributes[i]) {
            higher = this->StaffAttributes[i];
            winner = this->getName();
            staff1Won++;
        } else if(this->StaffAttributes[i] < other.StaffAttributes[i]) {
            higher = other.StaffAttributes[i];
            winner = other.getName();
            staff2Won++;
        } else {
            higher = this->StaffAttributes[i];
            winner = "Tie";
        }
        cout << setw(25) << attribute[i];
        cout << setw(2) << higher;
        cout << setw(5) << "";
        cout << setw(25) << winner << endl;
    }
    cout << endl;
    if(staff1Won > staff2Won) {
        cout << this->getName() << " won the most categories with " << staff1Won;
    } else if(staff1Won < staff2Won) {
        cout << other.getName() << " won the most categories with " << staff2Won;
    } else {
        cout << "There was a tie with both " << this->getName() << " and " << other.getName()
             << " both getting " << staff2Won << " categories won." << endl;
    }
}

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

    cout << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << StaffAttributes[ATTACKING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << StaffAttributes[ADAPTABILITY] << endl;

    cout << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << StaffAttributes[DEFENDING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Determination:" << setw(attributeWidth) << StaffAttributes[DETERMINATION] << endl;

    cout << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << StaffAttributes[FITNESS];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << StaffAttributes[DISCIPLINE] << endl;

    cout << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << StaffAttributes[MENTAL];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << StaffAttributes[MANMANAGEMENT] << endl;

    cout << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << StaffAttributes[TACTICAL];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << StaffAttributes[MOTIVATING] << endl;

    cout << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << StaffAttributes[TECHNICAL] << endl;
    cout << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << StaffAttributes[WORKINGWITHYOUNGSTERS] << endl;

    // Medical & Scouting
    cout << left << setw(headingWidth) << "Medical";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Scouting" << endl;

    cout << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << StaffAttributes[PHYSIOTHERAPY];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << StaffAttributes[JUDGINGPLAYERDATA] << endl;

    cout << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << StaffAttributes[SPORTSSCIENCE];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << StaffAttributes[JUDGINGTEAMDATA] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << StaffAttributes[PRESENTINGDATA] << endl;

    // GK Coaching & Knowledge
    cout << left << setw(headingWidth) << "GK Coaching";
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Knowledge" << endl;

    cout << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << StaffAttributes[GKDISTRIBUTION];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << StaffAttributes[JUDGINGABILITY] << endl;

    cout << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << StaffAttributes[GKHANDLING];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << StaffAttributes[JUDGINGPOTENTIAL] << endl;

    cout << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << StaffAttributes[GKSHOTSTOP];
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << StaffAttributes[JUDGINGSTAFFABILITY] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << StaffAttributes[NEGOTIATING] << endl;

    cout << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    cout << setw(spaceBetween) << "";
    cout << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << StaffAttributes[TACTICALKNOWLEDGE] << endl;
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

    outfile << left << setw(headingWidth) << "Attacking:" << setw(attributeWidth) << StaffAttributes[ATTACKING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Adaptability:" << setw(attributeWidth) << StaffAttributes[ADAPTABILITY] << endl;

    outfile << left << setw(headingWidth) << "Defending:" << setw(attributeWidth) << StaffAttributes[DEFENDING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Determination:" << setw(attributeWidth) << StaffAttributes[DETERMINATION] << endl;

    outfile << left << setw(headingWidth) << "Fitness:" << setw(attributeWidth) << StaffAttributes[FITNESS];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Level of Discipline:" << setw(attributeWidth) << StaffAttributes[DISCIPLINE] << endl;

    outfile << left << setw(headingWidth) << "Mental:" << setw(attributeWidth) << StaffAttributes[MENTAL];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Man Management:" << setw(attributeWidth) << StaffAttributes[MANMANAGEMENT] << endl;

    outfile << left << setw(headingWidth) << "Tactical:" << setw(attributeWidth) << StaffAttributes[TACTICAL];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Motivating:" << setw(attributeWidth) << StaffAttributes[MOTIVATING] << endl;

    outfile << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << StaffAttributes[TECHNICAL] << endl;
    outfile << left << setw(headingWidth) << "Working With Youngsters:" << setw(attributeWidth) << StaffAttributes[WORKINGWITHYOUNGSTERS] << endl;

    // Medical & Scouting
    outfile << left << setw(headingWidth) << "Medical";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Scouting" << endl;

    outfile << left << setw(headingWidth) << "Physiotherapy:" << setw(attributeWidth) << StaffAttributes[PHYSIOTHERAPY];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Player Data:" << setw(attributeWidth) << StaffAttributes[JUDGINGPLAYERDATA] << endl;

    outfile << left << setw(headingWidth) << "Sports Science:" << setw(attributeWidth) << StaffAttributes[SPORTSSCIENCE];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Team Data:" << setw(attributeWidth) << StaffAttributes[JUDGINGTEAMDATA] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Presenting Data:" << setw(attributeWidth) << StaffAttributes[PRESENTINGDATA] << endl;

    // GK Coaching & Knowledge
    outfile << left << setw(headingWidth) << "GK Coaching";
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Knowledge" << endl;

    outfile << setw(headingWidth) << "GK Distribution:" << setw(attributeWidth) << StaffAttributes[GKDISTRIBUTION];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Ability:" << setw(attributeWidth) << StaffAttributes[JUDGINGABILITY] << endl;

    outfile << setw(headingWidth) << "GK Handling:" << setw(attributeWidth) << StaffAttributes[GKHANDLING];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Potential:" << setw(attributeWidth) << StaffAttributes[JUDGINGPOTENTIAL] << endl;

    outfile << setw(headingWidth) << "GK Shot Stop:" << setw(attributeWidth) << StaffAttributes[GKSHOTSTOP];
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Judging Staff Ability:" << setw(attributeWidth) << StaffAttributes[JUDGINGSTAFFABILITY] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Negotiating:" << setw(attributeWidth) << StaffAttributes[NEGOTIATING] << endl;

    outfile << left << setw(headingWidth) << "" << setw(attributeWidth) << "";
    outfile << setw(spaceBetween) << "";
    outfile << setw(headingWidth) << "Tactical Knowledge:" << setw(attributeWidth) << StaffAttributes[TACTICALKNOWLEDGE] << endl;
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

    dataFile.close();
}

void Staff::readFromBinary(fstream& dataFile) {
    fstream &dataFileCopy = dataFile;
    dataFileCopy.read(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&name), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&age), sizeof(int));
    dataFileCopy.read(reinterpret_cast<char*>(&role), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&club), sizeof(string));

    for(auto & StaffAttribute : StaffAttributes) {
        dataFileCopy.read(reinterpret_cast<char*>(&StaffAttribute), sizeof(short int));
    }

    dataFileCopy.close();
}

/* Set Attributes */

void Staff::setCoaching(const short &attack, const short &defend, const short &fit,
                        const short &ment, const short &tact, const short &tech,
                        const short &workingWYoungsters)
{
    StaffAttributes[ATTACKING] = attack;
    StaffAttributes[DEFENDING] = defend;
    StaffAttributes[FITNESS] = fit;
    StaffAttributes[MENTAL] = ment;
    StaffAttributes[TACTICAL] = tact;
    StaffAttributes[TECHNICAL] = tech;
    StaffAttributes[WORKINGWITHYOUNGSTERS] = workingWYoungsters;
}

void Staff::setMedical(const short &physio, const short &ss)
{
    StaffAttributes[PHYSIOTHERAPY] = physio;
    StaffAttributes[SPORTSSCIENCE] = ss;
}

void Staff::setGoalKeeping(const short& dist, const short& hand, const short& ss)
{
    StaffAttributes[GKDISTRIBUTION] = dist;
    StaffAttributes[GKHANDLING] = hand;
    StaffAttributes[GKSHOTSTOP] = ss;
}

void Staff::setMental(const short& adapt, const short& det, const short& disc,
                      const short& mm, const short& mot)
{
    StaffAttributes[ADAPTABILITY] = adapt;
    StaffAttributes[DETERMINATION] = det;
    StaffAttributes[DISCIPLINE] = disc;
    StaffAttributes[MANMANAGEMENT] = mm;
    StaffAttributes[MOTIVATING] = mot;
}

void Staff::setScouting(const short& jPD, const short& jTD, const short& pD)
{
    StaffAttributes[JUDGINGPLAYERDATA] = jPD;
    StaffAttributes[JUDGINGTEAMDATA] = jTD;
    StaffAttributes[PRESENTINGDATA] = pD;
}

void Staff::setKnowledge(const short& jA, const short& jP, const short& jSA,
                         const short& n, const short& tK)
{
    StaffAttributes[JUDGINGABILITY] = jA;
    StaffAttributes[JUDGINGPOTENTIAL] = jP;
    StaffAttributes[JUDGINGSTAFFABILITY] = jSA;
    StaffAttributes[NEGOTIATING] = n;
    StaffAttributes[TACTICALKNOWLEDGE] = tK;
}

void Staff::setRandomAttributes() {
    for(short & StaffAttribute : StaffAttributes) {
        StaffAttribute = rand() % 20 + 1;
    }
}
