/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int maxSumWO3Consec(int *arr, int n) { 
    int sum[n]; 
    if (n >= 1) {
        sum[0] = arr[0]; 
    }
    if (n >= 2) {
        sum[1] = arr[0] + arr[1];
    }
    if (n > 2) {
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2])); 
    }
    for (int i = 3; i < n; i++) {
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]); 
    }
    return sum[n - 1]; 
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
    cout << "\Maximum subsequence sum\t:\t" << maxSumWO3Consec(arr,n); 
    return 0; 
}
