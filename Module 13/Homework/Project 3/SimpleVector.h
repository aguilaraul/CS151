#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib>
using namespace std ;

template <class T>
class SimpleVector {

private:
    T *aptr;
    int arraySize;
    int arrayCapacity;
    void subError();                     // Handles subscripts out of range

public:
    SimpleVector()                        // Default constructor
    { aptr = 0 ; arraySize = 0; arrayCapacity = 1; }
    explicit SimpleVector(int) ;                   // Constructor
    SimpleVector(const SimpleVector &) ;  // Copy constructor
    ~SimpleVector() ;                     // Destructor
    int size() { return arraySize ; }
    int capacity() { return arrayCapacity; }
    T &operator[](const int &) ;          // Overloaded [] operator
    void push_back(const T&);
    void pop_back();
    // Exception classes
    class ArrayFullException {
    public:
        ArrayFullException() = default;
    };
    class ArrayEmptyException : public exception {
    public:
        ArrayEmptyException() = default;
    };
};

//*************************************************************
//         Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s) {
    arraySize = 0;
    arrayCapacity = s;
    aptr = new T[s];

    for(int count = 0; count < arraySize; count++) {
        *(aptr + count) = {};
    }
}

//************************************************
// Copy Constructor for SimpleVector class       *
//************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
    arraySize = obj.arraySize ;
    arrayCapacity = obj.arrayCapacity;
    aptr = new T[arrayCapacity];
    for(int count = 0 ; count < arraySize ; count++)
        *(aptr + count) = *(obj.aptr + count) ;
}

//***************************************
// Destructor for SimpleVector class    *
//***************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (arraySize > 0)
        delete [] aptr ;
}

//*************************************************************
//              SubError function                             *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVector<T>::subError() {

    cout << "ERROR: Subscript out of range.\n" ;
    exit(0) ;
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// in the array indexed by the subscript.                     *
//*************************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub) {

    if (sub < 0 || sub >= arraySize)
        subError() ;
    return aptr[sub] ;
}

template<class T>
void SimpleVector<T>::push_back(const T &val) {
    if(size()+1 > capacity()) {
        throw ArrayFullException();
    }
    aptr[arraySize++] = val;
}

template <class T>
void SimpleVector<T>::pop_back() {
    if(size() == 0) {
        throw ArrayEmptyException();
    }
    arraySize--;
}

#endif
