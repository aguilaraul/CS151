// TestVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> int_vector;

	// Store numbers 1 through 10 in the vector
	for (int i = 0; i < 10; i++) {
		int_vector.push_back(i + 1);
	}

	// Display the numbers in the vector
	cout << "Numbers in the vector: ";
	for (int i = 0; i < int_vector.size(); i++) {
		cout << int_vector[i] << " ";
	}

	// Create vector for strings
	vector<string> string_vector;

	string_vector.push_back("Dallas");
	string_vector.push_back("San Diego");
	string_vector.push_back("Monterey");
	string_vector.push_back("Wailea");
	string_vector.push_back("Piai");
	string_vector.push_back("Lihue");

	// Display strings in the vector
	cout << "\nStrings in string_vector: ";
	for (int i = 0; i < string_vector.size(); i++) {
		cout << string_vector[i] << " ";
	}
	cout << endl;

	// Remove last 2 elements
	string_vector.pop_back();
	string_vector.pop_back();

	// Display strings in the vector
	cout << "\nStrings in string_vector after removing 2: ";
	for (int i = 0; i < string_vector.size(); i++) {
		cout << string_vector[i] << " ";
	}
	cout << endl;

	// Declare another vector of strings and add 2 elements to it
	vector<string> v2;
	v2.push_back("Palau");
	v2.push_back("Paris");

	cout << "\nStrings in v2:";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	// Swap elements from v2 and string_vector
	v2.swap(string_vector);
	v2[0] = "Los Angeles";
	
	cout << endl;
	cout << "\nStrings in v2 after swap and reassignment: ";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2.at(i) << " "; // using a function to retrieve instead of []
	}
	cout << endl;

	// check to see if v2 has elements:
	if (v2.empty()) {
		cout << "v2 is empty" << endl;
	} else {
		cout << "v2 is not empty" << endl;
	}

	// Redisplay the elements in the string_vector after swap
	cout << "\nStrings in string_vector after removing 2: ";
	for (int i = 0; i < string_vector.size(); i++) {
		cout << string_vector[i] << " ";
	}
	cout << endl;

	// Remove all elements from v2
	cout << "\nRemoving all elements from v2: " << endl;
	v2.clear();

	cout << "v2 is " << (v2.empty() ? "" : "not ") << "empty" << endl << endl;
	system("pause");
	return 0;
}
