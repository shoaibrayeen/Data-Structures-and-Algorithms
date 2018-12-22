//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int gen(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
     }
    else if (n % 2 == 0) {
        return 4 * gen(n / 2);
    }
    else {
        return 4 * gen(n / 2) + 1;
    }
}

void moserDeBruijn(int n) {
    cout << "\nMoser-de Bruijn Sequence\t:\t";
    for (int i = 0; i < n; i++) {
        cout << gen(i) << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "\nEnter N\t\t\t:\t";
    cin >> n;
    moserDeBruijn(n);
    return 0;
}
