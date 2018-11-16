//
//  q10.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
 
int dealnnoy(int n, int m) { 
    int dp[m + 1][n + 1]; 
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1; 
    }
    for (int i = 0; i <= m; i++)  {
        dp[0][i] = 1;     
    }
    for (int i = 1; i <= m; i++)  {
        for (int j = 1; j <= n; j++) {  
            dp[i][j] = dp[i - 1][j] +  dp[i - 1][j - 1] + dp[i][j - 1]; 
        }
    }
    return dp[m][n]; 
} 
  
int main() { 
    int n , m;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter m\t:\t";
    cin >> m;
    cout << dealnnoy(n, m) << endl; 
    return 0; 
} 
