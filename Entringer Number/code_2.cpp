//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
  
int Entringer_Number(int n, int k) { 
    int dp[n + 1][k + 1]; 
    memset(dp, 0, sizeof(dp)); 
    dp[0][0] = 1; 
    for (int i = 1; i <= n; i++)  {
        dp[i][0] = 0;     
    }
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++)  {
            dp[i][j] = dp[i][j - 1] +  dp[i - 1][i - j]; 
        }
    }
    return dp[n][k];  
} 
  
int main() { 
    int n;
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nEntringer Number\t:\t" << Entringer_Number(n, k) << endl; 
    return 0; 
} 
