/* 
 * author   Raul Aguilar
 * date     September 1, 2020
 *
 * CS 151 3228 Homework 1 Project 2
 */

#include <iostream>
#include "Country.h"

using namespace std;


Country::Country(string n, int pop, int a)
{
    name = n;
    population = pop;
    area = a;
}

string Country::getName()
{
    return name;
}

int Country::getPopulation() 
{
    return population;
}

int Country::getArea()
{
    return area;
}