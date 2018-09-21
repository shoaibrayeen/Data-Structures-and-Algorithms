//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int permutationCoeff(int n, int k) { 
    int P[n + 1][k + 1]; 
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= min(i, k); j++) {  
            if (j == 0) {
                P[i][j] = 1; 
            }
            else {
                P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]); 
            }
            P[i][j + 1] = 0; 
        } 
    } 
    return P[n][k]; 
} 
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout <<"\nThe result is\t:\t" << permutationCoeff(n,k);
    cout << endl;
    return 0;
}
