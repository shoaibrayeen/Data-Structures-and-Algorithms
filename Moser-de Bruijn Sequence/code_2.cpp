//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void moserDeBruijn(int n) {
    int S[n+1];
    
    S[0] = 0;
    S[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            S[i] = 4 * S[i / 2];
        }
        else {
            S[i] = 4 * S[i / 2] + 1;
        }
    }
    cout << "\nMoser-de Bruijn Sequence\t:\t";
    for (int i = 0; i < n; i++) {
        cout << S[i]  << " ";
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
