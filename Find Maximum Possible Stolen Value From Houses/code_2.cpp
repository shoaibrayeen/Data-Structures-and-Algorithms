//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int getMaximumStolenValue(vector<int> hval) {
    int n = int(hval.size());
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return hval[0];
    }
    if (n == 2) {
        return max(hval[0], hval[1]);
    }
    int dp[3];
    dp[0] = hval[0];
    dp[1] = max(hval[0], hval[1]);
    for (int i = 2; i < n; i++) {
        dp[2] = max(hval[i] + dp[0], dp[1]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[1];
}

int main() {
    int n;
    cout << "\nEnter Total Values\t:\t";
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter All Values\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nMaximum Stolen Value\t:\t" << getMaximumStolenValue(array) << "\n";
    return 0;
}
