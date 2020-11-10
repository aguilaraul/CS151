//
// Created by raula on 11/7/2020.
//

#include "Player.h"
#include <memory>

Player::Player()
    : Person()
{
    setRole("None");
    setClub("None");
    //setRandomAttributes();
}

Player::Player(const string &nation, const string &name, int age,
               const string &role, const string &club)
    : Person(nation, name, age)
{
    setRole(role);
    setClub(club);
    //setRandomAttributes();
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