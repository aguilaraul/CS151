#ifndef PROJECT_3_SORTABLEVECTOR_H
#define PROJECT_3_SORTABLEVECTOR_H
#include <iostream>
#include "SimpleVector.h"
using namespace std;

template<class T>
class SortableVector : public SimpleVector<T> {
public:
    explicit SortableVector(int);
    void sort();
    void swap(T &a, T &b);
};

template <class T>
SortableVector<T>::SortableVector(int size)
    : SimpleVector<T>(size) {};

template<class T>
void SortableVector<T>::sort() {
//    bool madeSwap = true;
//    for(int maxElement = this->size() - 1; maxElement > 0 && madeSwap; maxElement--) {
//        madeSwap = false;
//        for(int i = 0; i < maxElement; i++) {
//            if((this+i) > (this+i+1)) {
//                swap(*(this[i]), *(this[i+1]));
//                madeSwap = true;
//            }
//        }
//    }
    cout << this->size() << endl;
    cout << &this << endl;
}

template<class T>
void SortableVector<T>::swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif //PROJECT_3_SORTABLEVECTOR_H