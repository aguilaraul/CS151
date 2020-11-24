//
// Created by raula on 11/22/2020.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <iomanip>
using namespace std;

class LinkedList {
protected:
    struct ListNode
    {
        double value;
        ListNode* next;
        ListNode(double value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    ListNode* head;
public:
    ~LinkedList();
    void remove(double);
    // Homework 14
    LinkedList();
    void print() const;
    bool isMember(double);
    void add(double);
    void reverse();
    int search(double);
    void insert(double, int);

};

#endif //LINKEDLIST_H
