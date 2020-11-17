/**
 * hw8_project1.cpp
 * Author   Raul Aguilar
 * Date     November 15, 2020
 * CS 151 3228 Module 8 Homework 8 Project 1
 * Write a function that accepts a C-string as an argument and returns
 * the number of words contains in the string.
 *
 * Algorithm:
 * 1. Initialize C-string
 * 2. Get sentence from the user
 * 3. Count the number of words in the sentence:
 *  a. Loop through each character in the C-string
 *  b. If the current character is a punctuation mark and the next
 *  character is null terminator, then at the end of sentence and add
 *  previous word.
 *  c. If current character is not a punctuation mark and the next
 *  character is null terminator, then at the end of sentence and add
 *  previous word.
 *  d. If current character is space, add previous word
 * 4. Print out number of words in string/sentence
 */
#include <iostream>
using namespace std;

int countWords(const char*);

int main() {
    const int SIZE = 241;
    char *sentence = new char[SIZE];

    // Get line from user
    cout << "Enter a sentence to count the words:\n";
    cin.getline(sentence, SIZE);

    // Count number of words
    int words = countWords(sentence);
    cout << "Number of words: " << words << endl;
    delete [] sentence;
    return 0;
}

int countWords(const char* str) {
    int words = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(ispunct(str[i]) && (str[i+1] == '\0')) {
            // At end of sentence with punctuation
            words++;
        }
        if(str[i+1] == '\0' && !(ispunct(str[i]))) {
            // At end of sentence without punctuation
            words++;
        }
        if(isspace(str[i])) {
            // If current is space, then previous was word
            words++;
        }
    }
    return words;
}