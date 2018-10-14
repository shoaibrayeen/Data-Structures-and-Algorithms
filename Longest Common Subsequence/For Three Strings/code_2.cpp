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

int lcs( string s1 , string s2, string s3 ,  long m, long n , long o) {
    int L[m+1][n+1][o+1]; 
    for (int i=0; i<=m; i++) { 
        for (int j=0; j<=n; j++) { 
            for (int k=0; k<=o; k++) { 
                if (i == 0 || j == 0 || k==0) {
                    L[i][j][k] = 0; 
                }
                else if (X[i-1] == Y[j-1] && X[i-1] == Z[k-1] ) { 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 
                }
                else {
                    L[i][j][k] = max(max(L[i-1][j][k] , L[i][j-1][k]), L[i][j][k-1]); 
                }
            } 
        } 
    } 
    return L[m][n][o]; 
}

int main() {
    string s1 , s2 , s3;;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\n3rd String\t:\t";
    cin >> s3;
    cout << "\nLength of LCS\t:\t" << lcs( s1, s2 , s3 , s1.length(), s2.length() ,  s3.length() ) << endl;
    return 0;
}
