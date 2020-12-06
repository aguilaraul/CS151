/**
 * Player.cpp
 * Author:  Raul Aguilar
 * Date:    December 4, 2020
 * CS 151 3228 Final
 */
#include "Player.h"

Player::Player()
    : Person()
{
    setRole("None");
    setClub("None");
    setRandomAttributes();
}

Player::Player(const string &nation, const string &name, int age,
               const string &role, const string &club)
    : Person(nation, name, age)
{
    setRole(role);
    setClub(club);
    setRandomAttributes();
}

Player::~Player() = default;

void Player::setRole(const string &r) {
    this->role = r;
}

void Player::setClub(const string &c) {
    this->club = c;
}

string Player::getRole() {
    return role;
}

string Player::getClub() {
    return club;
}

string Player::to_string() {
    return Person::to_string() +
           " They are currently a " + role +
           " at " + club + '.';
}

void Player::printAttributes() const {
    cout << "Nation: " << nation << endl;
    cout << left << setw(6) << "Name:";
    cout << setw(25) << name;
    cout << right << setw(10) << "Role: " << role << endl;

    cout << left << setw(6) << "Age: " << setw(25) << age;
    cout << right << setw(10);
    cout << "Club: " << club << endl;

    int headingWidth = 25, headingSpace = 7, spaceBetween = 5, attributeWidth = 2;
    // Coaching & Mental
    cout << left << setw(headingWidth) << "Technical";
    cout << setw(headingSpace) << "";
    cout << left << setw(headingWidth) << "Mental";
    cout << setw(headingSpace) << "";
    cout << left << setw(headingWidth) << "Physical" << endl;

    cout << left << setw(headingWidth) << "Corners:" << setw(attributeWidth) << PlayerAttributes[CORNERS];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Aggression:" << setw(attributeWidth) << PlayerAttributes[AGGRESSION];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Acceleration:" << setw(attributeWidth) << PlayerAttributes[ACCELERATION] << endl;

    cout << left << setw(headingWidth) << "Crossing:" << setw(attributeWidth) << PlayerAttributes[CROSSING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Anticipation:" << setw(attributeWidth) << PlayerAttributes[ANTICIPATION];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Agility:" << setw(attributeWidth) << PlayerAttributes[AGILITY] << endl;

    cout << left << setw(headingWidth) << "Dribbling:" << setw(attributeWidth) << PlayerAttributes[DRIBBLING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Bravery:" << setw(attributeWidth) << PlayerAttributes[BRAVERY];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Balance:" << setw(attributeWidth) << PlayerAttributes[BALANCE] << endl;

    cout << left << setw(headingWidth) << "Finishing:" << setw(attributeWidth) << PlayerAttributes[FINISHING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Composure:" << setw(attributeWidth) << PlayerAttributes[COMPOSURE];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Jumping Reaching:" << setw(attributeWidth) << PlayerAttributes[JUMPINGREACH] << endl;

    cout << left << setw(headingWidth) << "First Touch:" << setw(attributeWidth) << PlayerAttributes[FIRSTTOUCH];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Concentration:" << setw(attributeWidth) << PlayerAttributes[CONCENTRATION];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Natural Fitness:" << setw(attributeWidth) << PlayerAttributes[NATURALFITNESS] << endl;

    cout << left << setw(headingWidth) << "Free Kick:" << setw(attributeWidth) << PlayerAttributes[FREEKICK];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Decisions:" << setw(attributeWidth) << PlayerAttributes[DECISIONS];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Pace:" << setw(attributeWidth) << PlayerAttributes[PACE] << endl;

    cout << left << setw(headingWidth) << "Heading:" << setw(attributeWidth) << PlayerAttributes[HEADING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Determination:" << setw(attributeWidth) << PlayerAttributes[DETERMINATION];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Stamina:" << setw(attributeWidth) << PlayerAttributes[STAMINA] << endl;

    cout << left << setw(headingWidth) << "Long Shots:" << setw(attributeWidth) << PlayerAttributes[LONGSHOTS];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Flair:" << setw(attributeWidth) << PlayerAttributes[FLAIR];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Strength:" << setw(attributeWidth) << PlayerAttributes[STRENGTH] << endl;

    cout << left << setw(headingWidth) << "Long Throws:" << setw(attributeWidth) << PlayerAttributes[LONGTHROWS];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Leadership:" << setw(attributeWidth) << PlayerAttributes[LEADERSHIP] << endl;

    cout << left << setw(headingWidth) << "Marking:" << setw(attributeWidth) << PlayerAttributes[MARKING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Off the Ball:" << setw(attributeWidth) << PlayerAttributes[OFFTHEBALL] << endl;

    cout << left << setw(headingWidth) << "Passing:" << setw(attributeWidth) << PlayerAttributes[PASSING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Positioning:" << setw(attributeWidth) << PlayerAttributes[POSITIONING] << endl;

    cout << left << setw(headingWidth) << "Penalty Taking:" << setw(attributeWidth) << PlayerAttributes[PENALTYTAKING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Teamwork:" << setw(attributeWidth) << PlayerAttributes[TEAMWORK] << endl;

    cout << left << setw(headingWidth) << "Tackling:" << setw(attributeWidth) << PlayerAttributes[TACKLING];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Vision:" << setw(attributeWidth) << PlayerAttributes[VISION] << endl;

    cout << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << PlayerAttributes[TECHNICAL];
    cout << setw(spaceBetween) << "";
    cout << left << setw(headingWidth) << "Work Rate:" << setw(attributeWidth) << PlayerAttributes[WORKRATE] << endl;
}

void Player::saveToFile() const {
    const string fileName = name + ".txt";
    ofstream outfile(fileName, ios::out);

    outfile << "Nation: " << nation << endl;
    outfile << left << setw(6) << "Name:";
    outfile << setw(25) << name;
    outfile << right << setw(10) << "Role: " << role << endl;

    outfile << left << setw(6) << "Age: " << setw(25) << age;
    outfile << right << setw(10);
    outfile << "Club: " << club << endl;

    int headingWidth = 25, headingSpace = 7, spaceBetween = 5, attributeWidth = 2;
    // Coaching & Mental
    outfile << left << setw(headingWidth) << "Technical";
    outfile << setw(headingSpace) << "";
    outfile << left << setw(headingWidth) << "Mental";
    outfile << setw(headingSpace) << "";
    outfile << left << setw(headingWidth) << "Physical" << endl;

    outfile << left << setw(headingWidth) << "Corners:" << setw(attributeWidth) << PlayerAttributes[CORNERS];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Aggression:" << setw(attributeWidth) << PlayerAttributes[AGGRESSION];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Acceleration:" << setw(attributeWidth) << PlayerAttributes[ACCELERATION] << endl;

    outfile << left << setw(headingWidth) << "Crossing:" << setw(attributeWidth) << PlayerAttributes[CROSSING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Anticipation:" << setw(attributeWidth) << PlayerAttributes[ANTICIPATION];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Agility:" << setw(attributeWidth) << PlayerAttributes[AGILITY] << endl;

    outfile << left << setw(headingWidth) << "Dribbling:" << setw(attributeWidth) << PlayerAttributes[DRIBBLING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Bravery:" << setw(attributeWidth) << PlayerAttributes[BRAVERY];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Balance:" << setw(attributeWidth) << PlayerAttributes[BALANCE] << endl;

    outfile << left << setw(headingWidth) << "Finishing:" << setw(attributeWidth) << PlayerAttributes[FINISHING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Composure:" << setw(attributeWidth) << PlayerAttributes[COMPOSURE];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Jumping Reaching:" << setw(attributeWidth) << PlayerAttributes[JUMPINGREACH] << endl;

    outfile << left << setw(headingWidth) << "First Touch:" << setw(attributeWidth) << PlayerAttributes[FIRSTTOUCH];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Concentration:" << setw(attributeWidth) << PlayerAttributes[CONCENTRATION];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Natural Fitness:" << setw(attributeWidth) << PlayerAttributes[NATURALFITNESS] << endl;

    outfile << left << setw(headingWidth) << "Free Kick:" << setw(attributeWidth) << PlayerAttributes[FREEKICK];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Decisions:" << setw(attributeWidth) << PlayerAttributes[DECISIONS];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Pace:" << setw(attributeWidth) << PlayerAttributes[PACE] << endl;

    outfile << left << setw(headingWidth) << "Heading:" << setw(attributeWidth) << PlayerAttributes[HEADING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Determination:" << setw(attributeWidth) << PlayerAttributes[DETERMINATION];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Stamina:" << setw(attributeWidth) << PlayerAttributes[STAMINA] << endl;

    outfile << left << setw(headingWidth) << "Long Shots:" << setw(attributeWidth) << PlayerAttributes[LONGSHOTS];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Flair:" << setw(attributeWidth) << PlayerAttributes[FLAIR];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Strength:" << setw(attributeWidth) << PlayerAttributes[STRENGTH] << endl;

    outfile << left << setw(headingWidth) << "Long Throws:" << setw(attributeWidth) << PlayerAttributes[LONGTHROWS];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Leadership:" << setw(attributeWidth) << PlayerAttributes[LEADERSHIP] << endl;

    outfile << left << setw(headingWidth) << "Marking:" << setw(attributeWidth) << PlayerAttributes[MARKING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Off the Ball:" << setw(attributeWidth) << PlayerAttributes[OFFTHEBALL] << endl;

    outfile << left << setw(headingWidth) << "Passing:" << setw(attributeWidth) << PlayerAttributes[PASSING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Positioning:" << setw(attributeWidth) << PlayerAttributes[POSITIONING] << endl;

    outfile << left << setw(headingWidth) << "Penalty Taking:" << setw(attributeWidth) << PlayerAttributes[PENALTYTAKING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Teamwork:" << setw(attributeWidth) << PlayerAttributes[TEAMWORK] << endl;

    outfile << left << setw(headingWidth) << "Tackling:" << setw(attributeWidth) << PlayerAttributes[TACKLING];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Vision:" << setw(attributeWidth) << PlayerAttributes[VISION] << endl;

    outfile << left << setw(headingWidth) << "Technical:" << setw(attributeWidth) << PlayerAttributes[TECHNICAL];
    outfile << setw(spaceBetween) << "";
    outfile << left << setw(headingWidth) << "Work Rate:" << setw(attributeWidth) << PlayerAttributes[WORKRATE] << endl;
    outfile.close();
}

void Player::saveToBinary() {
    const string fileName = name + ".dat";
    ofstream dataFile(fileName, ios::binary | ios::out);

    // Person data
    dataFile.write(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&name), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&age), sizeof(int));
    dataFile.write(reinterpret_cast<char*>(&role), sizeof(string));
    dataFile.write(reinterpret_cast<char*>(&club), sizeof(string));

    // Attributes
    for(auto &PlayerAttribute : PlayerAttributes) {
        dataFile.write(reinterpret_cast<char*>(&PlayerAttribute), sizeof(short int));
    }

    dataFile.close();
}

void Player::readFromBinary(fstream &dataFile) {
    fstream &dataFileCopy = dataFile;
    dataFileCopy.read(reinterpret_cast<char*>(&nation), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&name), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&age), sizeof(int));
    dataFileCopy.read(reinterpret_cast<char*>(&role), sizeof(string));
    dataFileCopy.read(reinterpret_cast<char*>(&club), sizeof(string));

    for(auto &PlayerAttribute:PlayerAttributes) {
        dataFileCopy.read(reinterpret_cast<char*>(&PlayerAttribute), sizeof(short));
    }

    dataFileCopy.close();
}

void Player::setTechnical(const short &corner, const short &cross, const short &dribble, const short &finish,
                          const short &ftouch, const short &fkick, const short &head, const short &lshot,
                          const short &lthrow, const short &mark, const short &pass, const short &penalty,
                          const short &tackle, const short &tech)
{
    PlayerAttributes[CORNERS] = corner;
    PlayerAttributes[CROSSING] = cross;
    PlayerAttributes[DRIBBLING] = dribble;
    PlayerAttributes[FINISHING] = finish;
    PlayerAttributes[FIRSTTOUCH] = ftouch;
    PlayerAttributes[FREEKICK] = fkick;
    PlayerAttributes[HEADING] = head;
    PlayerAttributes[LONGSHOTS] = lshot;
    PlayerAttributes[LONGTHROWS] = lthrow;
    PlayerAttributes[MARKING] = mark;
    PlayerAttributes[PASSING] = pass;
    PlayerAttributes[PENALTYTAKING] = penalty;
    PlayerAttributes[TACKLING] = tackle;
    PlayerAttributes[TECHNICAL] = tech;
}

void Player::setMental(const short &aggr, const short &anti, const short &brave, const short &compose,
                       const short &concen, const short &deci, const short &deter, const short &flair,
                       const short &leader, const short &offball, const short &pos, const short &team,
                       const short &vis, const short &work)
{
    PlayerAttributes[AGGRESSION] = aggr;
    PlayerAttributes[ANTICIPATION] = anti;
    PlayerAttributes[BRAVERY] = brave;
    PlayerAttributes[COMPOSURE] = compose;
    PlayerAttributes[CONCENTRATION] = concen;
    PlayerAttributes[DECISIONS] = deci;
    PlayerAttributes[DETERMINATION] = deter;
    PlayerAttributes[FLAIR] = flair;
    PlayerAttributes[LEADERSHIP] = leader;
    PlayerAttributes[OFFTHEBALL] = offball;
    PlayerAttributes[POSITIONING] = pos;
    PlayerAttributes[TEAMWORK] = team;
    PlayerAttributes[VISION] = vis;
    PlayerAttributes[WORKRATE] = work;
}

void Player::setPhysical(const short &accel, const short &agil, const short &bal, const short &jreach,
                         const short &nfitness, const short &pace, const short &sta, const short &str)
{
    PlayerAttributes[ACCELERATION] = accel;
    PlayerAttributes[AGILITY] = agil;
    PlayerAttributes[BALANCE] = bal;
    PlayerAttributes[JUMPINGREACH] = jreach;
    PlayerAttributes[NATURALFITNESS] = nfitness;
    PlayerAttributes[PACE] = pace;
    PlayerAttributes[STAMINA] = sta;
    PlayerAttributes[STRENGTH] = str;
}

void Player::setRandomAttributes() {
    for(short &PlayerAttribute : PlayerAttributes) {
        PlayerAttribute = rand() % 20 + 1;
    }
}