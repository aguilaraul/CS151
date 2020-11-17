/*
 * Dog.cpp
 *
 * Author	Raul Aguilar
 * Date		October 14, 2020
 *
 * CS 151 3228 Module 7 Lab Project 2
 * Dog class
 */
#include <iostream>
#include "Dog.h"

using namespace std;

Dog::Dog(string name, string breed)
	: Animal(name)
{
	setBreed(breed);
	cout << "A Dog " << getName() << " of breed " << getBreed() << " has been created." << endl;
}

void Dog::setBreed(string breed)
{
	this->breed = breed;
}

string Dog::getBreed()
{
	return this->breed;
}

void Dog::makeNoise()
{
	cout << "The Dog " << getName() << " is barking." << endl;
}

void Dog::showInfo()
{
	cout << "The Dog " << getName();
	cout << " of breed " << getBreed() << "." << endl;
}