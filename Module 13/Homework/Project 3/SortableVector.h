#ifndef PROJECT_3_SORTABLEVECTOR_H
#define PROJECT_3_SORTABLEVECTOR_H
#include <iostream>
#include "SimpleVector.h"
using namespace std;

template<class T>
class SortableVector : public SimpleVector<T> {
public:
    explicit SortableVector(int);
    void sort(SortableVector<T>&);
    void swap(T &a, T &b);
};

template <class T>
SortableVector<T>::SortableVector(int size)
    : SimpleVector<T>(size) {};

template<class T>
void SortableVector<T>::sort(SortableVector<T> &v) {
    bool madeSwap = true;
    for(int maxElement = v.size() - 1; maxElement > 0 && madeSwap; maxElement--) {
        madeSwap = false;
        for(int i = 0; i < maxElement; i++) {
            if(v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                madeSwap = true;
            }
        }
    }
}

template<class T>
void SortableVector<T>::swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif //PROJECT_3_SORTABLEVECTOR_H