//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int countFriendsPairings(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        if (i <= 2) {
            dp[i] = i;
        }
        else {
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "\nEnter Number of People\t\t:\t";
    cin >> n;
    cout << "Number of Different Pairs\t:\t" << countFriendsPairings(n) << endl;
    return 0;
}
