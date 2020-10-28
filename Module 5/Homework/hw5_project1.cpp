/*
 * Project1.cpp
 * Author:  Raul Aguilar
 * Date:    October 28, 2020
 *
 * CS 151 3228 Module 5 Homework 5 Project 1
 * Design a class Numbers that can be used to translate whole dollar
 * amounts in the range of 0 through 9999 into an English description
 * of the number.
 *
 * Algorithm:
 * 1. Accept input from user. Validate that number is between 0 and 9999
 * 2. Determine how many digits the number has
 * 3. Using the number of digits, select the most significant digit and
 * output it in English
 * 4. Remove the most significant digit to move place value lower
 * 5. Continue to determine the most significant digit, display it
 * in English, and lower the place value until the number is less than
 * 20
 */

#include <iostream>

using namespace std;

class Number
{
private:
    int number;

public:
    Number(int);
    const static string LESSTHAN20[];
    const static string TENS[];
    const static string HUNDRED;
    const static string THOUSAND;
    int getNumber();
    int parseDigits(int);
    void print();
};

Number::Number(int n)
{
    number = n;
}

const string Number::LESSTHAN20[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                              "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                              "eighteen", "nineteen" };
const string Number::TENS[] = { "twenty", "thrity", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const string Number::HUNDRED = "hundred";
const string Number::THOUSAND = "thousand";

int Number::getNumber()
{
    return number;
}

int Number::parseDigits(int num)
{
    int digits = 0;
    while (num != 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

void Number::print()
{
    int digits = parseDigits(number);
    int msd = 0;

    switch (digits)
    {
        case 4:
            msd = number / 1000;
            cout << LESSTHAN20[msd];
            cout << " " << THOUSAND << " ";
        case 3:
            number = number % 1000;
            msd = number / 100;
            cout << LESSTHAN20[msd];
            cout << " " << HUNDRED << " ";
        default:
            number = number % 100;
            if (number < 20)
            {
                cout << LESSTHAN20[number] << endl;
            } else
            {
                msd = number / 10;
                cout << TENS[msd - 2];
                cout << " " << LESSTHAN20[number % 10] << endl;
            }
    }
}


int inputNumber();

int main()
{
    int num = inputNumber();
    Number n(num);

    n.print();

    return 0;
}

int inputNumber()
{
    int num;
    bool validInput = false;
    cout << "Enter a number between 0 and 9999.\n";
    cin >> num;

    while (!validInput) {
        if (num < 0 || num > 9999) {
            cout << "Invalid input. Re-enter number between 0 and 9999.\n";
            cin >> num;
        } else {
            validInput = true;
        }
    }

    return num;
}