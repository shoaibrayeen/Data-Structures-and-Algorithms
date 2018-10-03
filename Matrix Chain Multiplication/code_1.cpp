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
  
int MatrixChainOrder(int* p, int i, int j) { 
    if(i == j) {
        return 0;
    }
    int min = INT_MAX; 
    int count; 
    for (int k = i; k < j; k++) { 
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j]; 
  
        if (count < min) {
            min = count; 
        }
    } 
    return min; 
} 
  
int main()  {
  int n;
  cout << "\nEnter Number of Matrix\t:\t";
  cin >> n;
  int a[n+1];
  cout << "\nEnter Dimenstions of Matrices\n";
  for(int i = 0; i <= n ; i++ ) {
    cin >> a[i];
  }
  cout << "\nMinimum number of multiplications\t:\t" << MatrixChainOrder(arr, 1, n-1));
  return 0; 
}
