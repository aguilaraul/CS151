/**
 * Staff.cpp
 * Author   Raul Aguilar
 * Date     December 12, 2020
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

/**
 * Compares the calling Staff object against another Staff object
 * passed by reference. Loops through all the attributes of a Staff,
 * determines which of the two Staff has the greater attribute
 * value, and prints the winner or tie of all the attributes.
 * @param other Staff object to compare calling object against
 */
void Staff::compare(const Staff &other) const {
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
    cout << " ! -- STAFF COMPARISON -- ! " << endl;
    for(int i = 0; i < numOfAttributes; i++) {
        if(StaffAttributes[i] > other.StaffAttributes[i]) {
            higher = StaffAttributes[i];
            winner = getName();
            staff1Won++;
        } else if(StaffAttributes[i] < other.StaffAttributes[i]) {
            higher = other.StaffAttributes[i];
            winner = other.getName();
            staff2Won++;
        } else {
            higher = StaffAttributes[i];
            winner = "Tie";
        }
        cout << setw(25) << attribute[i];
        cout << setw(2) << higher;
        cout << setw(5) << "";
        cout << setw(25) << winner << endl;
    }
    cout << endl;
    if(staff1Won > staff2Won) {
        cout << getName() << " won the most categories with " << staff1Won << "." << endl;
    } else if(staff1Won < staff2Won) {
        cout << other.getName() << " won the most categories with " << staff2Won << "." << endl;
    } else {
        cout << "There was a tie with both " << getName() << " and " << other.getName()
             << " both getting " << staff2Won << " categories won." << endl;
    }
}

/**
 * Prints the Staff's personal information and attributes to the
 * terminal
 */
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

//
// File I/O
//

/**
 * After the user elects to save a manually inputted Staff, the
 * personal information and attributes are converted and saved to a
 * formatted text file
 */
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

/**
 * After the user elects to save a manually inputted Player, the
 * personal information and attributes are converted and saved to a
 * binary file
 */
void Staff::saveToBinary() {
    const string fileName = name + ".dat";
    ofstream dataFile(fileName, ios::binary | ios::out);

    // Person data
    dataFile.write(nation.c_str(), nation.size() );
    dataFile.write("\0", sizeof(char));
    dataFile.write(name.c_str(), name.size());
    dataFile.write("\0", sizeof(char));
    dataFile.write(reinterpret_cast<char*>(&age), sizeof(age));
    dataFile.write(role.c_str(), role.size() );
    dataFile.write("\0", sizeof(char));
    dataFile.write(club.c_str(), club.size() );
    dataFile.write("\0", sizeof(char));

    //Attributes
    for(auto & StaffAttribute : StaffAttributes) {
        dataFile.write(reinterpret_cast<char*>(&StaffAttribute), sizeof(StaffAttribute));
    }

    dataFile.close();
}

/**
 * After a user selects to load in a Player via file, the fstream
 * opened in App is passed here. The fstream is used to read and set
 * the personal information and attributes of the Player.
 * @param dataFile
 */
void Staff::loadBinary(fstream& dataFile) {
    getline(dataFile, nation, '\0');
    getline(dataFile, name, '\0');
    dataFile.read(reinterpret_cast<char*>(&age), sizeof(age));
    getline(dataFile, role, '\0');
    getline(dataFile, club, '\0');

    for(auto &StaffAttribute : this->StaffAttributes) {
        dataFile.read(reinterpret_cast<char*>(&StaffAttribute), sizeof(StaffAttribute));
    }
}

//
// Set Staff Attributes
//

/**
 * After the attributes have been validated from App, this setter
 * function sets the Coaching attributes for a Staff member
 * @param attack The staff member's competency at coaching attacking
 * soccer
 * @param defend The ability of the staff member to coach the defensive
 * side of the game
 * @param fit This reflects a staff member's ability to ensure the
 * standards of player and squad fitness are developed and maintained
 * @param ment The staff member's approach to dealing with players on a
 * mental level
 * @param tact How tactically astute the staff member is
 * @param tech The ability of the staff member to teach the technical
 * side of the game
 * @param workingWYoungsters How successful a staff member is at
 * working with younger players
 */
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

/**
 * After the attributes have been validated from App, this setter
 * function sets the Medical attributes for a Staff member
 * @param physio Reflects the physiotherapist's competency in
 * issuing high-quality treatment to both prevent and rehabilitate
 * injuries
 * @param ss The competency of a staff member to accurately manage
 * every player's fitness level and injury risk in such a way that they
 * are abe to keep them in condition to play regular soccer
 */
void Staff::setMedical(const short &physio, const short &ss)
{
    StaffAttributes[PHYSIOTHERAPY] = physio;
    StaffAttributes[SPORTSSCIENCE] = ss;
}

/**
 * After the attributes have been validated from App, this setter
 * function sets the Goalkeeper Coaching attributes for a Staff member
 * @param dist The staff member's competency at coaching a goalkeeper
 * in the quality and effectiveness of his distribution
 * @param hand The staff member's competency at coaching a goalkeeper's
 * Handling attribute as well as impacting upon their Aerial Reach,
 * Command of Area, and Communication
 * @param ss The staff member's competency at coaching a goalkeeper's
 * ability to stop all type of shots
 */
void Staff::setGoalKeeping(const short& dist, const short& hand, const short& ss)
{
    StaffAttributes[GKDISTRIBUTION] = dist;
    StaffAttributes[GKHANDLING] = hand;
    StaffAttributes[GKSHOTSTOP] = ss;
}

/**
 * After the attributes have been validated from App, this setter
 * function sets the Mental attributes for a Staff member
 * @param adapt A high Adaptability attribute will enable a staff
 * member to settle quickly in a new country but will also help a
 * little in settling in at new clubs and new roles
 * @param det The mental desire of the staff member to succeed; the
 * staff member's own innate drive to better themselves
 * @param disc This reflects the level of discipline the staff member
 * is likely to take into their approach
 * @param mm How well the member of staff is able to deal with those
 * around them and particularly below them
 * @param mot The mental ability of a staff member to motivate their
 * players
 */
void Staff::setMental(const short& adapt, const short& det, const short& disc,
                      const short& mm, const short& mot)
{
    StaffAttributes[ADAPTABILITY] = adapt;
    StaffAttributes[DETERMINATION] = det;
    StaffAttributes[DISCIPLINE] = disc;
    StaffAttributes[MANMANAGEMENT] = mm;
    StaffAttributes[MOTIVATING] = mot;
}

/**
 * After the attributes have been validated from App, this setter
 * function sets the Scouting attributes for a Staff member
 * @param jPD The ability of a Data Analyst to understand data
 * concerning an individual player and interpret it in a manner useful
 * to the head coach
 * @param jTD The ability of a Data Analyst to understand data
 * concerning a team and interpret it in a manner useful to the head
 * coach
 * @param pD The ability of a Data Analyst to present their data in an
 * efficient and easily digestible manner to the head coach and to the
 * players
 */
void Staff::setScouting(const short& jPD, const short& jTD, const short& pD)
{
    StaffAttributes[JUDGINGPLAYERDATA] = jPD;
    StaffAttributes[JUDGINGTEAMDATA] = jTD;
    StaffAttributes[PRESENTINGDATA] = pD;
}

/**
 * After the attributes have been validated from App, this setter
 * function sets the Knowledge attributes for a Staff member
 * @param jA The ability of the staff member to appraise the current
 * standard of a given player of team
 * @param jP The ability of the staff member to appraise the potential
 * future levels of performance of a given player or team while taking
 * into account several factors that could influence the outcome
 * @param jSA The ability of a Technical Director to judge which
 * abilities of staff members need improvement and act on that
 * information
 * @param n How good the staff member is at negotiating transfer deals
 * @param tK The tactical knowledge possessed by a staff member
 */
void Staff::setKnowledge(const short& jA, const short& jP, const short& jSA,
                         const short& n, const short& tK)
{
    StaffAttributes[JUDGINGABILITY] = jA;
    StaffAttributes[JUDGINGPOTENTIAL] = jP;
    StaffAttributes[JUDGINGSTAFFABILITY] = jSA;
    StaffAttributes[NEGOTIATING] = n;
    StaffAttributes[TACTICALKNOWLEDGE] = tK;
}

/**
 * Sets random attribute values during default initialization
 */
void Staff::setRandomAttributes() {
    for(short & StaffAttribute : StaffAttributes) {
        StaffAttribute = rand() % 20 + 1;
    }
}
