//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k , int p ) { 
    int C[k+1]; 
    C[0] = 1;
  
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[k];
}
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int n;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nEnter p\t:\t";
    int p;
    cin >> p;
    cout <<"\nThe result is\t:\t" << binomialCoeff(n,k,p);
    cout << endl;
    return 0;
}
