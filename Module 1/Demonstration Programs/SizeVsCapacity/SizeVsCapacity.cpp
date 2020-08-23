// SizeVsCapacity.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <vector>
#include <iostream>

using namespace std;

int main() {
	cout << "Show the size and capacity of a vector as items are added." << endl << endl << endl;

	vector<int> int_vector;
	cout << "Before any entries, size is " << int_vector.size()
		<< " and capacity is " << int_vector.capacity() << endl;

	for (int i = 1; i <= 12; i++) {
		cout << "Adding " << i << " ";
		int_vector.push_back(i);

		for (int j = 0; j < int_vector.size(); j++) {
			cout << int_vector[j] << " ";
		}

		cout << " size is " << int_vector.size() << " and capacity is " << int_vector.capacity() << endl;
	}
}
