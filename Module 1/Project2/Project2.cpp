/*
 * author   Raul Aguilar
 * date     September 1, 2020
 *
 * CS 151 3228 Homework 1 Project 2
 *
 *
 *
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "Country.h"

using namespace std;

vector<Country> southAmerica;

void populateVector(vector<Country>& countries);

int main()
{
    int totalPopulation = 0;
    int totalArea = 0;

    populateVector(southAmerica);

    return 0;
}

void populateVector(vector<Country>& countries)
{
    string line;
    ifstream fin("countries.txt");

    while (getline(fin, line))
    {
        // Find name of country
        string name = line.substr(line.find_first_of('\"') + 1, line.find_last_of('\"') - 1);
        line = line.erase(0, line.find_last_of('\"') + 2);

        // Find population of country
        string delimiter = " ";
        int pos = line.find(delimiter);
        int pop = stoi(line.substr(0, pos));
        line = line.erase(0, pos + delimiter.length());

        // Find area of country
        pos = line.find(delimiter);
        int area = stoi(line.substr(0, pos));

        Country c(name, pop, area);
        countries.push_back(c);

    }
    fin.close();
}