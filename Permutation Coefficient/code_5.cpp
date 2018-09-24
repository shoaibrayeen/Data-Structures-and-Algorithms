//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int PermutationCoeff(int n, int k) { 
    int Fn = 1, Fk; 
    for (int i = 1; i <= n; i++) { 
        Fn *= i; 
        if (i == n - k) 
        Fk = Fn; 
    } 
    int coeff = Fn / Fk; 
    return coeff; 
}  
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nThe result is\t:\t" << PermutationCoeff(n,k);
    cout << endl;
    return 0;
}
