//
// Created by raula on 12/14/2020.
//

#ifndef FM20COMPARE_ATTRIBUTERANGE_H
#define FM20COMPARE_ATTRIBUTERANGE_H

#include <iostream>
using namespace std;

class AttributeRange{
private:
    short input;
    short lower = 1;
    short upper = 20;
public:
    // Exception class
    class OutOfRange : public exception {};
    // Functions
    AttributeRange(short low, short high) {
        lower = low;
        upper = high;
    }
    int getAttributeValue() {
        cin >> input;
        if(input < lower || input > upper) {
            throw OutOfRange();
        }
        return input;
    }
};

#endif //FM20COMPARE_ATTRIBUTERANGE_H
