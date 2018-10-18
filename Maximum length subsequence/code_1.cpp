/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int maxLenSub(int arr[], int n) { 
    int mls[n], max = 0; 
    for (int i=0; i<n; i++) {
        mls[i] = 1; 
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (abs(arr[i] - arr[j]) <= 1 && mls[i] < mls[j] + 1) {
                mls[i] = mls[j] + 1; 
            }
        }
    }    
    for (int i=0; i<n; i++) {
        if (max < mls[i]) {
            max = mls[i]; 
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
    cout << "\Length of LIS\t:\t" << lis_fun(arr,n); 
    return 0; 
}
