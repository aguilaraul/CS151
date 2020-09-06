/*
 * author   Raul Aguilar
 * date     September 1, 2020
 *
 * CS 151 3228 Homework 1 Project 2
 * Fill a vector with Country objects based from South America in
 * ascending order based on the country's area.
 *
 * Algorithm:
 * 1. Populate the vector with Country objects
 * Create a text file with a list of the countries' name, population,
 * and area on each line in alphebetical order.
 * Read in the file, parse each line using delimiters
 * Construct the Country object using the information parsed
 * Scan the vector to find a smaller area compared to the current
 * country.
 * Insert the current country after the smaller area
 * 2. Print report showing each country
 * Print headers for the name, population, and area
 * Left-align the country's name
 * Right-align the population and area
 * Print the total population and total area below the list of
 * countries.
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Country.h"

using namespace std;

vector<Country> southAmerica;

void populateVector(vector<Country>& countries);
void printCountries(vector<Country> countries);

int main()
{
    populateVector(southAmerica);
    printCountries(southAmerica);

    return 0;
}

void populateVector(vector<Country>& countries)
{
    string line;
    ifstream fin("countries.txt");
    vector<Country>::iterator iter;

    while (getline(fin, line))
    {
        int index = 0;
        // Find name of country
        string name = line.substr(line.find_first_of('\"') + 1, line.find_last_of('\"') - 1);
        line = line.erase(0, line.find_last_of('\"') + 2);

        // Parse population of country
        string delimiter = " ";
        int pos = line.find(delimiter);
        int pop = stoi(line.substr(0, pos));
        line = line.erase(0, pos + delimiter.length());

        // Parse area of country
        pos = line.find(delimiter);
        int area = stoi(line.substr(0, pos));

        Country c(name, pop, area);

        for (int i = 0; i < countries.size(); i++)
        {
            if (countries[i].getArea() < c.getArea())
            {
                index = i + 1;
            }
        }

        iter = countries.begin() + index;
        countries.insert(iter, c);
    }
    fin.close();
}

void printCountries(vector<Country> countries)
{
    int totalPopulation = 0;
    int totalArea = 0;
    // Print headers
    cout << left << setw(16) << "Country";
    cout << setw(10) << " Population";
    cout << right << setw(11) << " Area" << endl;
    cout << "----------------";
    cout << " ----------";
    cout << " -----------" << endl;
    
    // Print Country name, population, and area
    for (Country c : countries)
    {
        cout << left << setw(16) << c.getName();
        cout << " " << right << setw(10) << c.getPopulation();
        cout << " " << setw(11) << c.getArea() << endl;
        totalPopulation += c.getPopulation();
        totalArea += c.getArea();
    }
    
    // Display total population and area
    for (int i = 0; i < 39; i++) {
        cout << "-";
    }
    cout << endl;
    cout << " " << setw(26) << totalPopulation;
    cout << " " << setw(11) << totalArea << endl;
}