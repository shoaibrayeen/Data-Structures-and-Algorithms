//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;

int lcs( string X, string Y, long m, long n )  {    
    int L[2][n + 1]; 
    bool bi; 
    for (int i = 0; i <= m; i++) { 
        bi = i & 1; 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) {
                L[bi][j] = 0; 
            }
            else if (X[i-1] == Y[j-1]) {
                 L[bi][j] = L[1 - bi][j - 1] + 1; 
            }
            else {
                L[bi][j] = max(L[1 - bi][j], L[bi][j - 1]); 
            }
        } 
    }  
    return L[bi][n]; 
} 
  

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nLength of LCS\t:\t" << lcs( s1, s2 , s1.length(), s2.length() ) << endl;
    return 0;
}
