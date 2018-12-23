//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;



void sequence(int n) {
    int P[n+1];
    P[0] = 0;
    P[1] = 1;
    P[2] = 1;
    for (int i = 3; i <= n; i++) {
        P[i] = P[P[i - 1]] + P[i - P[i - 1]];
    }
    
    cout << "\nNewman-Conway Sequence\t:\t";
    for ( int i = 1; i <= n; i++ ) {
        cout << P[i] << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\nEnter N\t\t\t:\t";
    cin >> n;
    sequence(n);
    return 0;
}
