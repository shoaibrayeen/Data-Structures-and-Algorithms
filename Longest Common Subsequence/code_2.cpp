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
   int L[m+1][n+1]; 
   int i, j; 
   for (i=0; i<=m; i++)  { 
     for (j=0; j<=n; j++)  { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   return L[m][n]; 
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
