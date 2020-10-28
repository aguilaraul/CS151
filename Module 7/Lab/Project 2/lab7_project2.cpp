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
 * 1. Create a parent class named Animal
 *	- One private string for the animal's name.
 *	- One constructor that takes one argument of string to set the
 *	instance member, and print message that the Animal has been created
 *	- Getter and setter functions for the instance member
 *	- No-argument function named sleep that prints message that Animal
 *	is asleep
 *	- No-argument function named makeNoise that print message that
 *	Animal is making a noise
 *  - a showInfo function that prints "The Animal <its name>"
 * 2. Create a Bird class
 *	- Is child of Animal class
 *	- Single constructor that takes one argument, a string to set the
 *	instance member using a member initialization list, and print the
 *	message "A Bird has been created"
 *	- Override makeNoise to "The Bird is chirping"
 *	- Override showInfo to "The Bird <its name>"
 * 3. Create a Dog class
 *	- Is child of Animal class
 *	- One private string for its breed
 *	- One constructor that takes two arugments for its name and its
 *	breed using a member initialization list, and print the message
 *	that "A Dog <> of breed <> has been created"
 *	- Getter and setter for breed
 *	- Override makeNoise to print "The Dog is barking."
 *  - Override showInfo to "The Dog <> of breed <>"
 * 
 * Questions:
 * 1. The base class is named Animal.
 * 2. The derived classes are Bird and Dog
 * 3. Animal does not have a parent class
 * 4. The functions showInfo() and makeNoise() are both overridden in
 * the child classes. Sleep() is not overridden.
 * 5. If the instance member 'name' in Animal was made protected, then
 * the child classes would have direct access to it and would not need
 * getters and setters.
 * If the 'name' were left to private and access to Animal was changed
 * to protected, then the child classes would not have direct access
 * and would require getters and setters.
 */
#include <iostream>
#include "Animal.h"
#include "Bird.h"
#include "Dog.h"

using namespace std;

int main()
{
	Animal Oscar("Oscar");
	Dog Inka("Inka", "Mutt");
	Bird Tweety("Tweety");

	// Show info
	Oscar.showInfo();
	Inka.showInfo();
	Tweety.showInfo();
	
	cout << endl;
	
	// Make noise
	Oscar.makeNoise();
	Inka.makeNoise();
	Tweety.makeNoise();
	
	cout << endl;
	
	// Sleep
	Oscar.sleep();
	Inka.sleep();
	Tweety.sleep();

	return 0;
}