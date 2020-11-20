/* LinkedList.h - Generic class allowing representation of a linked list
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Lab
 * Problem statement:  This file contains the definition for a generic
 *    Node class and a generic LinkedList class.  Enhance an generic LinkedList.h
 *    class with several functions to make the class more usable.
 *
 *    Functions should throw a run-time exception if there would be confusion between
 *    what is returned (successful) and something couldn't be returned.
 *
 * Algorithm:
 *    Classes already included are  Node<T> and LinkedList<T>
 *    Functions already given are:  full constructor, addFirst, addLast, add,
 *        getFirst, getLast(), get, indexOf, getSize, isEmpty, removeFirst,
 *        removeLast, and clear
 *
 *    Functions to be written are:
 *        display, remove, removeAt, find, findLast, contains, and set
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>                          // catch run-time errors
using namespace std ;

/******************************
 *                            *
 *  Template for Node class   *
 *                            *
 ******************************/
template<class T>
class Node {
public:
    T data ;                // value or object stored in the node
    Node<T> *next ;         // pointer to the next node

    // No-arg constructor
    Node() {
        next = nullptr  ;
    }

    // Constructor with one parameter
    Node(T myData) {
        this->data = myData ;   // stores value in node's data field
        next = nullptr ;
    }
} ;

/*****************************************
 *                                       *
 *   Template for the LinkedList class   *
 *                                       *
 *****************************************/
template<class T>
class LinkedList {

private:
    Node<T> *head, *tail;         // pointers to first and last nodes
    int size;                       // number of nodes in this list

public:

    // Prototypes of functions already present
    LinkedList();                           // constructor

    void addFirst(T myData);                // add an element to the list
    void addLast(T myData);
    void add(int index, T myData);

    T getFirst();                           // accessors
    T getLast();
    T get(int index);
    int indexOf(T myData);
    int getSize();
    bool isEmpty();

    T removeFirst() noexcept(false);  // remove an element or clear
    T removeLast() noexcept(false);
    void clear() ;

    // Function prototypes to be provided in this lab
    bool contains(T myData);
    int lastIndexOf(T myData);
    bool remove(T myData);
    T removeAt(int index);
    bool set(int index, T myData);
    void display();
} ;

/************************************
*                                   *
*     Function implementations      *
*                                   *
*************************************/

// Constructor
template<typename T>
LinkedList<T>::LinkedList() {                    // An empty list
    head = tail = nullptr;
    size = 0;
}

// Add node to beginning of the list
template<typename T>
void LinkedList<T>::addFirst(T myData) {
    Node<T> *newNode = new Node<T>(myData);    // Create new node and ptr
    newNode->next = head;                      // Assign value of head ptr to next ptr of new node
    head = newNode;                            // Set head to point at new node
    size++;                                    // increment size of LinkedList

    if (tail == nullptr)
        tail = head;                           // set tail ptr to new node if list was empty
}

// Add node to the end of the list
template<typename T>
void LinkedList<T>::addLast(T myData) {
    if (tail == nullptr) {                      // list is empty
        head = tail = new Node<T>(myData);     // point head and tail to new node
    } else {
        tail->next = new Node<T>(myData);      // create new node
        tail = tail->next;                     // set tail ptr to new node
    }

    size++;
}

// Add node at specific index
template<typename T>
void LinkedList<T>::add(int index, T myData) {
    if (index == 0) {                           // add node at beginning of list
        addFirst(myData);
    } else if (index >= size) {                 // add node at end of list
        addLast(myData);
    } else {                                    // insert this element between two nodes
        Node<T> *current = head;               // loop to node before this one
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T> *temp = current->next;         // one after this one
        current->next = new Node<T>(myData);
        (current->next)->next = temp;
        size++;
    }
}

// Get data from first node
template<typename T>
T LinkedList<T>::getFirst() {
    if (size == 0) {
        throw runtime_error("Index out of range") ; // no nodes in the list
    } else {
        return head->data;                     //retrieve value in first node
    }
}

// Get data from last node
template<typename T>
T LinkedList<T>::getLast() {                    // no nodes in the list
    if (size == 0) {
        throw runtime_error("Index out of range") ; // retrieve value in last node
    } else {
        return tail->data;
    }
}

// Get node at the specific index
template<typename T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index > size - 1)
        throw runtime_error("Index out of range") ;

    Node<T> *current = head;                // walk list
    for (int i = 0; i < index; i++)
        current = current->next;            // point to next node

    return current->data;                   // get value if found
}

// Get the index of a specific node
template<typename T>
int LinkedList<T>::indexOf(T myData) {
    Node<T> *current = head ;
    for (int i = 0 ; i < size ; i++) {
        if (current->data == myData)        // walk list to find value
            return i;
        current = current->next;
    }
    return -1;                             // return -1 if value not found
}


// Get the number of nodes in the list (number added - number removed)
template<typename T>
int LinkedList<T>::getSize() {
    return size;
}

// Remove first node from list
template<typename T>
T LinkedList<T>::removeFirst() noexcept(false) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else {
        Node<T> *temp = head;             // create new ptr temp - point to same place as head
        head = head->next;                // point to the next object beyond the first
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
        T myData = temp->data;
        delete temp;                      // delete node temp is pointing to
        return myData;                    // may or may not use this value
    }
}

// Remove last node from the list
template<typename T>
T LinkedList<T>::removeLast() noexcept(false) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else if (size == 1) {
        Node<T> *temp = head;
        head = tail = nullptr;
        size = 0;
        T myData = temp->data ;
        delete temp;                          // delete node temp is pointing to
        return myData;                        // may or may not use this value
    } else {
        Node<T> *current = head;              // set current to point at what head points at
        for (int i = 0; i < size - 2; i++)   // walk list moving current ptr to end
            current = current->next;

        Node<T> *temp = tail;
        tail = current;
        tail->next = nullptr;
        size--;
        T myData = temp->data;
        delete temp;
        return myData;
    }
}

// Clear the list - takes time but frees up memory
template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {          // if still a node in list
        Node<T> *temp = head;         // set temp ptr to what head points at
        head = head->next;            // point head at next node
        delete temp;                  // delete the node temp is pointing to
    }
    head = tail = nullptr;            // the empty list
    size = 0;
}

// See if the list is empty
template<typename T>
bool LinkedList<T>::isEmpty() {
    cout << "in isEmpty(), size is now " << size ;
    return head == nullptr;                   // no nodes in list
}

/**
 * Display the contents of the list on the console. Print "(null)" if
 * the list is empty
 */
template<class T>
void LinkedList<T>::display() {
    if(!head) {
        cout << "(null)";
        return;
    }

    Node<T> *nPtr = head;
    while(nPtr) {
        cout << nPtr->data << " ";
        nPtr = nPtr->next;
    }
}

/**
 * Determine if the list contains a specific data element. Return true
 * if found, otherwise return false.
 */
template<class T>
bool LinkedList<T>::contains(T myData) {
    if(!head) {
        return false;
    }
    Node<T> *nPtr = head;
    while(nPtr) {
        if(nPtr->data == myData) {
            return true;
        }
        nPtr = nPtr->next;
    }
    return false;
}

/**
 * Remove a node with a specific data element. Return false if the
 * element is not found, otherwise return true after removal.
 */
template<class T>
bool LinkedList<T>::remove(T myData) {
    Node<T> *nPtr, *prevNPtr;

    // If list is empty then return false
    if(!head) return false;

    // Determine if first node is one to delete
    if(head->data == myData) {
        nPtr = head;
        head = head->next;
        size--;
        delete nPtr;
        return true;
    } else {
        // Initialize nPtr to the head of the list
        nPtr = head;

        // Skip nodes whose value member is not number
        while(nPtr != nullptr && nPtr->data != myData) {
            prevNPtr = nPtr;
            nPtr = nPtr->next;
        }

        // Link the previous node to the node after
        // the one being deleted
        if(nPtr) {
            prevNPtr->next = nPtr->next;
            size--;
            delete nPtr;
            return true;
        }
    }
    return false;
}

template<class T>
T LinkedList<T>::removeAt(int index) {
    if(index < 0 || index >= size) {
        throw runtime_error("Invalid index");
    }
    if(index == 0) {
        return removeFirst();
    } else if(index == size-1) {
        return removeLast();
    } else {
        Node<T> *current = head, *previous;
        for(int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        T myData = current->data;
        size--;
        current->next = nullptr;
        delete current;
        return myData;
    }


}

template<class T>
bool LinkedList<T>::set(int index, T myData) {
    if(index < 0 || index >= size) {
        return false;
    }
    Node<T> *current = head;
    for(int i = 0; i < index;i++) {
        current = current->next;
    }
    current->data = myData;
    return true;
}

template<class T>
int LinkedList<T>::lastIndexOf(T myData) {
    int index = -1;
    Node<T> *current = head;
    for(int i = 0; i < size; i++) {
        if(current->data == myData) {
            index = i;
        }
        current = current->next;
    }
    return index;
}

#endif