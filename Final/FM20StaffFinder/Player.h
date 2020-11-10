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
    struct PlayerAttributes {
//@TODO: Fill Player Attributes
    } Attributes;
    void setCoaching(short int, short int, short int,
                     short int, short int, short int, short int);
    void setMedical(short int, short int);
    void setGoalKeeping(short int, short int, short int);
    void setMental(short int, short int, short int, short int,
                   short int);
    void setScouting(short int, short int, short int);
    void setKnowledge(short int, short int, short int,
                      short int, short int);
    void setRandomAttributes();
protected:
    string role;
    string club;
public:
    Player();
    Player(const string&, const string&, int,
          const string&, const string&);
    ~Player();
    void setRole(const string&);
    void setClub(const string&);
    string getRole();
    string getClub();
    string to_string() override;
};


#endif //FM20STAFFFINDER_PLAYER_H
