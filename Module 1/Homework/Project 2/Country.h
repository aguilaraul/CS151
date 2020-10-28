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
	Country(string name, int population, int area);
	string getName();
	int getPopulation();
	int getArea();
};
#endif // !COUNTRY_H
