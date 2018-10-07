//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 


int nswp(int n) { 
    int dp[n + 1]; 
    dp[0] = dp[1] = 1; 
    for (int i = 2; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] + dp[i - 2]; 
    }
    return dp[n]; 
} 

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << nswp(number);
    cout << endl;
    return 0;
}
