/**
 * Raul Aguilar
 * November 9, 2020
 * CS 151 3228 Midterm Problem 1
 */
#include <iostream>
#include <cstring>
using namespace std;

void replaceSubstring(char*, char*, char*);

int main() {
    char original[250];
    char find[50];
    char replace[50];

    // Get original
    cout << "Enter original string:\n";
    cin.getline(original, 250);

    // Get string to replace
    cout << "Enter string to replace:\n";
    cin.getline(find, 50);

    // Get replacement string
    cout << "Enter the replacement:\n";
    cin.getline(replace, 50);

    replaceSubstring(original, find, replace);
    cout << "With all replacements made:\n" << original << endl;

    return 0;
}

void replaceSubstring(char* original, char* find, char* replace) {
    char* found = strstr(original, find);
    while(found != nullptr) {
        strncpy(found, replace, strlen(replace));
        found = strstr(original, find);
    }
}
