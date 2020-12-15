/**
 * Player.h
 *
 * Author:  Raul Aguilar
 * Date:    November
 * CS 151 3228 Final Project
 * Player header file
 */

#ifndef FM20STAFFFINDER_PLAYER_H
#define FM20STAFFFINDER_PLAYER_H
#include "Person.h"
using namespace std;

class Player : public Person {
private:
    int numOfAttributes = 36;
    short int PlayerAttributes[36] = {};
    enum attributes
    {
        // Technical
        CORNERS, CROSSING, DRIBBLING, FINISHING, FIRSTTOUCH, FREEKICK, HEADING, LONGSHOTS,
        LONGTHROWS, MARKING, PASSING, PENALTYTAKING, TACKLING, TECHNICAL,
        // Mental
        AGGRESSION, ANTICIPATION, BRAVERY, COMPOSURE, CONCENTRATION, DECISIONS, DETERMINATION,
        FLAIR, LEADERSHIP, OFFTHEBALL, POSITIONING, TEAMWORK, VISION, WORKRATE,
        // Physical
        ACCELERATION, AGILITY, BALANCE, JUMPINGREACH, NATURALFITNESS, PACE, STAMINA, STRENGTH
    };


protected:
    string role;
    string club;
    void setRandomAttributes();
public:
    Player();
    Player(const string&, const string&, int,
           const string&, const string&);
    ~Player() override;
    void setRole(const string&);
    void setClub(const string&);
    string getRole();
    string getClub();

    string to_string() override;
    void compare(const Player&) const;

    void printAttributes() const;

    void saveToFile() const;
    void saveToBinary();

    void readFromBinary(fstream &);

    void setTechnical(const short&, const short&, const short&, const short&, const short&,
                      const short&, const short&, const short&, const short&, const short&,
                      const short&, const short&, const short&, const short&);
    void setMental(const short&, const short&, const short&, const short&, const short&,
                   const short&, const short&, const short&, const short&, const short&,
                   const short&, const short&, const short&, const short&);
    void setPhysical(const short&, const short&, const short&, const short&, const short&,
                     const short&, const short&, const short&);
};


#endif //FM20STAFFFINDER_PLAYER_H
