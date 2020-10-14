/*
 * Animal.cpp
 *
 * Author	Raul Aguilar
 * Date		October 14, 2020
 *
 * CS 151 3228 Module 7 Lab Project 2
 * Animal class
 */
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal(string name)
{
	setName(name);
	cout << "The Animal " << getName() << " has been created." << endl;
}

void Animal::setName(string name)
{
	this->name = name;
}

string Animal::getName()
{
	return name;
}

void Animal::sleep()
{
	cout << "The Animal " << getName() << " is asleep." << endl;
}

void Animal::makeNoise()
{
	cout << "The Animal " << getName() << " is making a noise." << endl;
}

void Animal::showInfo()
{
	cout << "The Animal " << getName() << endl;
}