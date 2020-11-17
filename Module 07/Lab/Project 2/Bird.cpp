/*
 * Bird.cpp
 *
 * Author	Raul Aguilar
 * Date		October 14, 2020
 *
 * CS 151 3228 Module 7 Lab Project 2
 * Bird class
 */
#include <iostream>
#include "Bird.h"

using namespace std;

Bird::Bird(string name)
	: Animal(name)
{
	cout << "A Bird " << getName() << " has been created." << endl;
}

void Bird::makeNoise()
{
	cout << "The Bird " << getName() << " is chirping." << endl;
}

void Bird::showInfo()
{
	cout << "The Bird " << getName() << endl;
}