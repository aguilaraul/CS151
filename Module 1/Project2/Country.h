/* 
 * author   Raul Aguilar
 * date     September 1, 2020
 *
 * CS 151 3228 Homework 1 Project 2
 */

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
using namespace std;

class Country
{
    private:
        string name;
        int population;
        int area;

    public:
        Country(string name, int pop, int area);
        string getName();
        int getPopulation();
        int getArea();
};
#endif