//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int sequence(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return sequence(sequence(n - 1)) + sequence(n - sequence(n - 1));
    }
}

void print(int n) {
    cout << "\nNewman-Conway Sequence\t:\t";
    for ( int i = 1; i <= n; i++ ) {
        cout << sequence(i) << "  ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "\nEnter N\t\t\t:\t";
    cin >> n;
    print(n);
    return 0;
}
