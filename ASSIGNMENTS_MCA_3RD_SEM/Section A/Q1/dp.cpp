//
//  q1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.


#include<iostream>
#include<climits>
using namespace std;
/*
    Time Complexity  : O(n^3)
    Space Complexity : O(n^2)
*/
void printBrackets(int i , int j , int n  , int *bracket , char &val) {
    if ( i == j) {
        cout << val;                                                    // print Matrix
        val++;
        return;
    }
    cout << "(";                                                        // print opening bracket
    int k = *((bracket + i*n ) + j);                                    // calculating value of index
    printBrackets(i , k , n , bracket , val );                          // print brackets from i to k
    printBrackets( k + 1 , j , n , bracket , val );                     // print brackets from k + 1 to j
    cout << ")";                                                        // print closing bracket

}
void MatrixChainOrder(int *dim, int n) {
    int temp[n][n] , bracket[n][n];                                             // creating two new tables
    for (int i = 1; i < n; i++) {                                               // updating primary diagonal of table to zero
        temp[i][i] = 0;
    }
    int count  = 0;
    for (int p = 2; p < n; p++) {
        for (int  i = 1; i < n - p + 1; i++) {                                  // i <= k < j for calculating min
            int j = i + p - 1;
            temp[i][j] = INT_MAX;                                              // storing max value in table so that can update min value
            for (int k = i; k <= j-1; k++) {                                  // calculating all possible value for temp[i,j]
                int temp_var = temp[i][k] + temp[k+1][j] + dim[i-1]*dim[k]*dim[j];   // storing result in temp var
                count++;
                if (temp_var < temp[i][j]) {
                    temp[i][j] = temp_var;                                      // if minimum , update temp[i,j]
                    bracket[i][j] = k;
                }
            }
        }
    }
    cout << "\nNumber of Comparisons\t:\t" << count;
    cout << "\nMinimum number of multiplications\t:\t" << temp[1][n-1];
    cout << "\nThe order of Matrix\t:\t";
    char start_letter = 'P';
    printBrackets( 1 , n-1 , n , *bracket , start_letter );
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
