/*
 * Animal.h
 * 
 * Author	Raul Aguilar
 * Date		October 14, 2020
 * 
 * CS 151 3228 Module 7 Lab Project 2
 * Animal header
 */
#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal
{
private:
	string name;
public:
	Animal(string);
	void setName(string);
	string getName();
	void sleep();
	void makeNoise();
	void showInfo();
};

#endif // !ANIMAL_H
