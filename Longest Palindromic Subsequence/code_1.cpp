//
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <string.h>
using namespace std;

int lps(string X, long i, long j) {
    if (i == j) {
        return 1;
    }
    if (X[i] == X[j] && i + 1 == j) {
        return 2;
    }
    if (X[i] == X[j]) {
        return lps (X, i+1, j-1) + 2;
    }
    return max( lps(X, i, j-1), lps(X, i+1, j) );
}

int main() {
    string X;
    cout << "\nEnter String\t\t:\t";
    getline(cin , X);
    cout << "\nLength of LPS\t\t:\t" << lps(X, 0, X.length()-1) << endl;
    return 0;
}
