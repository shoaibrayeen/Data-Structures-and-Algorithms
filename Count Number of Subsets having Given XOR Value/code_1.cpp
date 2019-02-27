//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int getNumberOfSubsetXOR(vector<int>arr, int k) {
    int n = int(arr.size());
    int max_ele = arr[0];
    for (int i = 1; i < n; i++ ) {
        if (arr[i] > max_ele) {
            max_ele = arr[i];
        }
    }
    int m = (1 << (int)(log2(max_ele) + 1) ) - 1;
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
        }
    }
    return dp[n][k];
}

int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter Array Element\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nEnter XOR value\t:\t";
    cin >> n;
    cout << "\nNumber of Subsets\t:\t" << getNumberOfSubsetXOR(array , n) << "\n";
    return 0;
}
