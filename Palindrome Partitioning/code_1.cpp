//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int minPalPartion(string str) {
    long n = str.length();
    int C[n];
    bool P[n][n];
    
    int j;
    for (int i = 0; i < n; i++ ) {
        P[i][i] = true;
    }
    for (int L = 2; L <= n; L++ ) {
        for (int i = 0; i < n-L+1; i++ ) {
            j = i + L - 1;
            if (L == 2) {
                P[i][j] = (str[i] == str[j]);
            }
            else {
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (P[0][i] == true) {
            C[i] = 0;
        }
        else {
            C[i] = INT_MAX;
            for( j = 0; j < i; j++) {
                if(P[j+1][i] == true && 1+C[j]<C[i]) {
                    C[i]=1+C[j];
                }
            }
        }
    }
    return C[n-1];
}


int main() {
    string s;
    cout << "\nEnter String\t:\t";
    cin >> s;
    cout << "\nMinimum Cuts needed for Palindrome Partintioning\t:\t " << minPalPartion(s) << "\n";
    return 0;
}
