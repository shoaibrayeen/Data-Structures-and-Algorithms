//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream> 
#include<climits> 
using namespace std; 
  
int MatrixChainOrder(int *dim, int n) { 
    int temp[n][n]; 
    int i, j, k, L, q; 
    for (i = 1; i < n; i++) {
        temp[i][i] = 0; 
    }
    for (L=2; L<n; L++) { 
        for ( i = 1; i< n-L+1; i++) { 
            j = i + L - 1; 
            temp[i][j] = INT_MAX; 
            for ( k = i; k <= j-1; k++) { 
                q = temp[i][k] + temp[k+1][j] + dim[i-1]*dim[k]*dim[j]; 
                if (q < temp[i][j]) {
                    temp[i][j] = q; 
                }
            } 
        } 
    } 
  
    return temp[1][n-1]; 
}
int main()  {
    int n;
    cout << "\nEnter Number of Matrix\t:\t";
    cin >> n;
    int dim[n+1];
    cout << "\nEnter Dimenstions of Matrices\n";
    for(int i = 0; i <= n ; i++ ) {
        cin >> dim[i];
    }
    cout << "\nMinimum number of multiplications\t:\t" << MatrixChainOrder(dim, n+1) << endl;;
    return 0;
}
