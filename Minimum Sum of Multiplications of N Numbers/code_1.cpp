//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

long long dp[1000][1000];

long long sum(vector<int> a, int i, int j) {
    long long ans = 0;
    for (int k = i; k <= j; k++) {
        ans = (ans + a[k]) % 100;
    }
    return ans;
}

long long getMinimumSum(vector<int> a, int i, int j) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], (getMinimumSum(a, i, k) + getMinimumSum(a, k + 1, j) + (sum(a, i, k) * sum(a, k + 1, j))));
    }
    return dp[i][j];
}

void intialize(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
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
    intialize(n);
    cout << "\nMinimum Sum\t:\t" << getMinimumSum(array , 0 , n -1 ) << "\n";
    return 0;
}

