//
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <string.h>
using namespace std;

int lps(string X) {
    long n = X.length();
    int table[n][n];
    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
    }
    
    int j;
    for (int cl=2; cl<=n; cl++) {
        for (int i=0; i<n-cl+1; i++) {
            j = i+cl-1;
            if (X[i] == X[j] && cl == 2) {
                table[i][j] = 2;
            }
            else if (X[i] == X[j]) {
                table[i][j] = table[i+1][j-1] + 2;
            }
            else {
                table[i][j] = max(table[i][j-1], table[i+1][j]);
            }
        }
    }
    
    return table[0][n-1];
}

int main() {
    string X;
    cout << "\nEnter String\t\t:\t";
    getline(cin , X);
    cout << "\nLength of LPS\t\t:\t" << lps(X) << endl;
    return 0;
}
