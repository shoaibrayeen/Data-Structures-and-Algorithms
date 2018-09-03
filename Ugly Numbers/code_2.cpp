//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

// CPP program to find nth ugly number
// C++ program to find n'th Ugly number
#include<iostream>
using namespace std;

/* Function to get the nth ugly number*/
unsigned getNthUglyNo(unsigned n) {
    unsigned ugly[n];
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
    
    ugly[0] = 1;
    for (int i=1; i<n; i++) {
        next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2 = i2+1;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3 = i3+1;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5 = i5+1;
            next_multiple_of_5 = ugly[i5]*5;
        }
    }
    return next_ugly_no;
}
int main() {
    cout << "\nEnter Number\t:\t";
    unsigned int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << getNthUglyNo(number);
    cout << endl;
    return 0;
}
