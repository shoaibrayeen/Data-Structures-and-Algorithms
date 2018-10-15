/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int productSubSeqCount(int *arr , int n , int k) {
    int dp[k + 1][n + 1]; 
    memset(dp, 0, sizeof(dp)); 
    for (int i = 1; i <= k; i++) { 
        for (int j = 1; j <= n; j++) { 
            dp[i][j] = dp[i][j - 1]; 
            if (arr[j - 1] <= i && arr[j - 1] > 0) {
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
            }
        } 
    } 
    return dp[k][n]; 
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
    int k;
    cout << "\nEnter k\t:\t";
    cin >> k;
    cout << "\Length of LIS\t:\t" << productSubSeqCount(arr , n , k); 
    return 0; 
}
