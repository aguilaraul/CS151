/**
 * hw12_project2.cpp
 * Author   Raul Aguilar
 * Date     November 15, 2020
 * CS 151 3228 Module 12 Homework 12 Project 2
 * Write an abstract class that takes a non-negative integer and
 * returns the corresponding terms of the sequence.
 *
 * Algorithm:
 * 1. If k < m, print all of the terms fun(k) through fun(m)
 * 2. If k < m, sum all of the terms fun(k) through fun(m)
 * 3. Print the sum of the sequence
 */
#include <iostream>
using namespace std;

class AbstractSeq {
public:
    virtual int fun(int k) = 0;
    /**
     * Where k < m, print all the terms fun(k) through fun(m) of the
     * sequence
     * @param k Starting term of sequence (inclusive)
     * @param m Ending term of sequence (inclusive)
     */
    void printSeq(int k, int m) {
        if(k < m) {
            for(int i = k; i <= m; i++) {
                cout << fun(i) << " ";
            }
            cout << endl;
        }
    }
    /**
     * Where k < m, returns the sum of all the terms of the sequence
     * fun(k) through fun(m)
     * @param k Starting term of the sequence (inclusive)
     * @param m Ending term of the sequence (inclusive)
     * @return Sum of terms fun(k) through fun(m)
     */
    int sumSeq(int k, int m) {
        if(k < m) {
            int sum = 0;
            for(int i = k; i <= m; i++) {
                sum += fun(i);
            }
            return sum;
        }
        return 0;
    }
};

class OddSeq : public AbstractSeq {
public:
    int fun(int k) override {
        return 2 * k + 1;
    }
};

class EvenSeq : public AbstractSeq {
public:
    int fun(int k) override {
        return 2 * k;
    }
};


int main() {
    OddSeq oddSeq;
    EvenSeq evenSeq;

    cout << "Odd Sequence of terms 0 through 15:\n";
    oddSeq.printSeq(0, 15);
    cout << "Sum of terms 4 through 12:\n";
    cout << oddSeq.sumSeq(4, 12) << endl << endl;

    cout << "Even Sequence of terms 6 through 21:\n";
    evenSeq.printSeq(6, 21);
    cout << "Sum of terms 11 through 19:\n";
    cout << evenSeq.sumSeq(11, 19) << endl;

    return 0;
}
