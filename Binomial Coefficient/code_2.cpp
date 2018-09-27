//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) 
{ 
    int C[n+1][k+1]; 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j]; 
        } 
    } 
  
    return C[n][k]; 
}
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout <<"\nThe result is\t:\t" << binomialCoeff(n,k);
    cout << endl;
    return 0;
}
