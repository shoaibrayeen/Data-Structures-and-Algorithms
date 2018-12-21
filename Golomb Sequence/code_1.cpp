//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int findGolomb(int n) {
    if (n == 1) {
        return 1;
    }
    return 1 + findGolomb(n - findGolomb(findGolomb(n - 1)));
}

void printGolomb(int n) {
    cout << "\nGolomb Sequence\t:\t";
    for (int i = 1; i <= n; i++) {
        cout << findGolomb(i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\nEnter N\t\t\t:\t";
    cin >> n;
    printGolomb(n);
    return 0;
}
