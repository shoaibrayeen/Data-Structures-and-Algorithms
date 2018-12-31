//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int count(int n) {
    if (n < 4) {
        return -1;
    }
    int rem = n % 4;
    if (rem == 0) {
        return n / 4;
    }
    else if (rem == 1) {
        if (n < 9) {
            return -1;
        }
        return (n - 9) / 4 + 1;
    }
    else if (rem == 2) {
        return (n - 6) / 4 + 1;
    }
    else {
        if (n < 15) {
            return -1;
        }
        return (n - 15) / 4 + 2;
    }
}


int main() {
    cout << "\nEnter N\t:\t";
    int n;
    cin >> n;
    cout << "\nMaximum Composite Number\t:\t" << count(n) << endl;
}
