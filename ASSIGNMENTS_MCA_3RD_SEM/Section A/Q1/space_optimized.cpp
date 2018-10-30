//
//  q1_memoized.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<iostream>
#include<climits>
using namespace std;


/*
  it'll take O(n^3)
  array_size = size*(size - 1) / 2
  index = size*row + column - (row+1)*(row+2)/2
  (row+1)*(row+2)/2 -> ignoring diagonal elements and i > j elements
 */
void MatrixChainOrder(int *dim, int n) {
    int size = n*(n-1)/2;
    int minM[size];
    int count  = 0;
    for (int p = 2; p < n; p++) {
        for (int  i = 1; i < n - p + 1; i++) { // i <= k < j for calculating min
            int j = i + p - 1;
            if( i <= j) {
                int i_j = n*i + j - ((i+1)*(i+2)/2);
                minM[i_j] = INT_MAX;
                for (int k = i; k <= j-1; k++) {
                    int i_k = n*i + k - ((i+1)*(i+2)/2);
                    int k_j = n*(k+1) + j - ((k+2)*(k+3)/2);
                    if ( i == k) {
                        i_k = 0;
                    }
                    if( k + 1 == j ) {
                        k_j = 0;
                    }
                    int temp = minM[i_k] + minM[k_j] + dim[i-1]*dim[k]*dim[j];
                    count++;
                    if (temp < minM[i_j]) {
                        minM[i_j] = temp;
                    }
                }
            }
        }
    }
    cout << "\nNumber of Comparisons\t:\t" << count;
    cout << "\nMinimum number of multiplications\t:\t" << minM[2*(n-2)] << endl;
}

int main()  {
    int n;
    cout << "\nEnter Number of Matrix\t:\t";
    cin >> n;
    
    int *dim = new int[n+1];
    int j = 1;
    cout << "Enter Dimension of " << j << " Matrix\n";
    cout << "Enter Row\t:\t";
    cin >> dim[0];
    cout << "\nEnter Column\t:\t";
    cin >> dim[1];
    for(int i = 1 ; i < n; i++ ) {
        j++;
        cout << "Enter Dimension of " << j << " Matrix\n";
        int row , column;
        cout << "Enter Row\t:\t";
        cin >> row;
        cout << "\nEnter Column\t:\t";
        cin >> column;
        while( dim[i] != row){
            cout << "\nMatrix not compatible\n";
            cout << "Enter Row\t:\t";
            cin >> row;
            cout << "\nEnter Column\t:\t";
            cin >> column;
        }
        dim[i+1] = column;
    }
    MatrixChainOrder(dim , n+1);
    cout << endl;
    return 0;
}
