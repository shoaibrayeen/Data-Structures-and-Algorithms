//
//  q4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 28/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.

//    array[i]*i

#include<bits/stdc++.h> 
using namespace std; 
  
int maxSum(int arr[], int n) { 
  sort(arr, arr + n); 
  int sum = 0; 
  for (int i = 0; i < n; i++) {
    sum += (arr[i]*i); 
  }
  return sum; 
} 

int main() { 
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    int a[n];
    for ( int i = 0; i < n; i++ ) {
      cin >> a[i];
    }
    cout << "\nResult\t:\t" << maxSum(a, n) << endl; 
    return 0; 
} 
