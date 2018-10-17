/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int longestSubseqWithDiffOne(int arr[], int n) { 
    int dp[n]; 
    for (int i = 0; i< n; i++) {
        dp[i] = 1; 
    }
    for (int i=1; i<n; i++) { 
        for (int j=0; j<i; j++) { 
            if ((arr[i] == arr[j]+1) || (arr[i] == arr[j]-1)) {
                dp[i] = max(dp[i], dp[j]+1); 
            }
        } 
    } 
    int result = 1; 
    for (int i = 0 ; i < n ; i++) {
        if (result < dp[i]) {
            result = dp[i]; 
        }
    }
    return result; 
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
    cout << "\nResult is\t:\t" << longestSubseqWithDiffOne(arr,n); 
    return 0; 
}
