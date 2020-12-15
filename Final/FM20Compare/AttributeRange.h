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
    class OutOfRange : public exception {
    public:
        const char* what() const noexcept override {
            return "Please enter a value between 1 and 20.\n";
        }
    };
    // Functions
    AttributeRange(){};
    short getAttributeValue() {
        cin >> input;
        if(input < lower || input > upper) {
            throw OutOfRange();
        }
        return input;
    }
};

#endif //FM20COMPARE_ATTRIBUTERANGE_H
