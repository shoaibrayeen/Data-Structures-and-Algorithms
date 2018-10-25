/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <bits/stdc++>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int *arr, int N, int K) { 
    sort(arr, arr+N); 
    int dp[N]; 
    dp[0] = 0; 
    for (int i = 1; i < N; i++) { 
        dp[i] = dp[i-1]; 
        if (arr[i] - arr[i-1] < K) { 
            if (i >= 2) {
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]); 
            }
            else {
                dp[i] = max(dp[i], arr[i] + arr[i-1]); 
            }
        } 
    } 
    return dp[N - 1]; 
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
    cout << "\nEnter K\t:\t";
    int k;
    cin >> k;
    cout << "\Maximum Sum Pair\t:\t" << maxSumPairWithDifferenceLessThanK(arr , n , k); 
    return 0; 
}
