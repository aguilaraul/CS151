/*
 * Dog.h
 *
 * Author	Raul Aguilar
 * Date		October 14, 2020
 *
 * CS 151 3228 Module 7 Lab Project 2
 * Dog header
 */
#ifndef DOG_H
#define DOG_H
#include "Animal.h"
using namespace std;

class Dog : public Animal
{
private:
	string breed;
public:
	Dog(string, string);
	void setBreed(string);
	string getBreed();
	void makeNoise();
	void showInfo();
};

#endif // !DOG_H
