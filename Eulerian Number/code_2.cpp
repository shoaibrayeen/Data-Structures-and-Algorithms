//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
 
int eulerian(int n, int m) { 
    int dp[n + 1][m + 1]; 
    for (int i = 1; i <= n; i++) { 
        for (int j = 0; j <= m; j++) {
            if (i > j) { 
                if (j == 0) {
                    dp[i][j] = 1; 
                }
                else {
                    dp[i][j] = ((i - j) * dp[i - 1][j - 1]) +  ((j + 1) * dp[i - 1][j]); 
                }
            } 
        } 
    } 
  
    return dp[n][m];  
}  
  
int main() { 
    int n , m;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter m\t:\t";
    cin >> m;
    cout << eulerian(n, m) << endl; 
    return 0; 
} 
