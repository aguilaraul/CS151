#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));
    vector<int> numbers;
    vector<int>::iterator iter;
    int index = 0;

    cout << "Numbers in array:" << endl;
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
    }
    cout << "---" << endl;

    int j = 0;
    while(j < 3) {
        int num = (rand() % RAND_MAX)%10;

        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] < num) {
                index = i;
                cout << "Array:" << numbers[i];
                cout << " ";
                cout << "Random:" << num;
                cout << endl;
            }
        }
        iter = numbers.begin() + index;
        numbers.insert(iter, num);
        j++;
    }

    for(iter = numbers.begin(); iter < numbers.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}