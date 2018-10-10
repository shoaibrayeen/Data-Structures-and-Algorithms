/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int maxSumIS(int *arr, int n) { 
    int i, j, max = 0; 
    int msis[n]; 
    for ( i = 0; i < n; i++ ) {
        msis[i] = arr[i]; 
    }
    for ( i = 1; i < n; i++ ) {
        for ( j = 0; j < i; j++ ) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i]; 
            }
        }
    }
    for ( i = 0; i < n; i++ ) {
        if ( max < msis[i] ) {
            max = msis[i]; 
        }
    }
    return max; 
}  
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Sequence\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    cout << "\Length of LIS\t:\t" << maxSumIS(arr,n); 
    return 0; 
}
