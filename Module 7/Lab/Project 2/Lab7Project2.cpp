/*
 * Lab7Project2.cpp
 * 
 * Author	Raul Aguilar
 * Date		October 14, 2020
 * 
 * CS 151 3228 Module 7 Lab Project 2
 * Write classes representing animals, birds, and dogs
 * 
 * Algorithm:
 * 
 */
#include <iostream>
#include "Animal.h"
#include "Bird.h"

using namespace std;

int main()
{
	Animal dog = Animal("Doofus");
	Bird lily = Bird("Lily");

	cout << "My dogs name is " << dog.getName() << endl;
	dog.makeNoise();
	lily.makeNoise();

	return 0;
}