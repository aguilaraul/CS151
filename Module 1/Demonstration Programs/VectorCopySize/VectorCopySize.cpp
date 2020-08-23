// VectorCopySize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void show_vector(vector<int>);

int main() {
    // Create int vector using the Vector class
    cout << "Creating a vector of size 7" << endl;
    cout << "Constructor will initialize the element values to 0" << endl;
    vector<int> v(7);

    // Display the values in v using an iterator
    show_vector(v);
    cout << endl;

    // Change and display values in v
    cout << "Setting values in the vector" << endl;
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }
    show_vector(v);
    cout << endl;

    // Increase capacity by 10 and display
    cout << "Reserving vector size for v of 10" << endl;
    v.reserve(10);
    cout << "The capacity is now " << v.capacity() << endl << endl;

    // Put some numbers into the vector
    cout << "Pushing back 5 new numbers into the vector" << endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    show_vector(v);

    cout << "Reserving vector size for v of size + 10" << endl;
    v.reserve(v.size() + 10);
    show_vector(v);
    cout << "It's capacity is now " << v.capacity() << endl << endl;

    // Create and copy or assign vector v's contents to copy vector
    cout << "Creating another vector and assigning v's contents to it" << endl;
    cout << "Change the first element in the copy to 42" << endl;
    cout << "The copy will have a capacity the same as the number of elements needed" << endl;
    vector<int> the_copy = v;
    the_copy[0] = 42;

    // Display the values of the copy
    show_vector(the_copy);
    cout << "It's capacity is " << the_copy.capacity() << endl << endl;

    // Show that there are two vectors with different memory locations
    cout << "Show the addresses of the two vectors" << endl;
    cout << "Address of v is: " << &v << endl;
    cout << "Address of the_copy is: " << &the_copy << endl;
    cout << endl;

    system("pause");
    return 0;
}


void show_vector(vector<int> int_vector) {
    vector<int>::iterator iter;
    for (iter = int_vector.begin(); iter != int_vector.end(); iter++) {
        cout << *iter << " ";
        cout << endl << "The size is " << int_vector.size() << endl;
    }
}